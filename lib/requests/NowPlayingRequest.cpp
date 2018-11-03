#include "NowPlayingRequest.h"
#include "RequestInvocationContext.h"
#include "RequestHandler.h"
#include "UserMapper.h"
#include "IOutputHandler.h"

#include "entities/NotPlaying.h"
#include "entities/Track.h"

QString NowPlayingRequest::trigger() const
{
	return ".np";
}

RequestResponse NowPlayingRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	const QString &nick = arguments.value(0, who);

	Track *nowPlaying = getRecentTrack(nick, context, &TrackFilter::nowPlaying);

	if (nowPlaying)
	{
		return RequestResponse("templates/NowPlaying.qml", nowPlaying);
	}

	NotPlaying *notPlaying = new NotPlaying();
	notPlaying->setUser(nick);

	return RequestResponse("templates/NotPlaying.qml", notPlaying);
}
