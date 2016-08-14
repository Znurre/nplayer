#include "NowPlayingRequest.h"
#include "RequestInvocationContext.h"
#include "RequestHandler.h"
#include "UserMapper.h"
#include "IOutputHandler.h"

#include "entities/TracksEnvelope.h"
#include "entities/NotPlaying.h"

#include "components/ITemplateComponent.h"

NowPlayingRequest::NowPlayingRequest()
{
	qRegisterMetaType<TracksEnvelope *>();
}

QString NowPlayingRequest::trigger() const
{
	return ".np";
}

RequestResponse NowPlayingRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(arguments);

	Track *nowPlaying = getNowPlaying(who, context);

	if (nowPlaying)
	{
		return RequestResponse("templates/NowPlaying.qml", nowPlaying);
	}

	NotPlaying *notPlaying = new NotPlaying();
	notPlaying->setUser(who);

	return RequestResponse("templates/NotPlaying.qml", notPlaying);
}

Track *NowPlayingRequest::getNowPlaying(const QString &who, const RequestInvocationContext &context) const
{
	InformationResourceRepository &repository = context.informationResourceRepository();
	IdGenerator &idGenerator = context.idGenerator();
	UserMapper &userMapper = context.userMapper();

	const RequestHandler requestHandler(repository, idGenerator);
	const TracksEnvelope *recentTracks = requestHandler
		.get<TracksEnvelope>("user.getRecentTracks"
			, as::limit = 1
			, as::user = userMapper.map(who)
			, as::nick = who
		);

	if (recentTracks)
	{
		for (Track *track : recentTracks->tracks())
		{
			if (track->nowPlaying())
			{
				return track;
			}
		}
	}

	return nullptr;
}
