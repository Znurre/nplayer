#include "LastPlayedRequest.h"

#include "entities/Track.h"

QString LastPlayedRequest::trigger() const
{
	return ".lp";
}

RequestResponse LastPlayedRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	const QString &nick = arguments.value(0, who);

	Track *track = getRecentTrack(nick, context, &TrackFilter::any);

	return RequestResponse("templates/LastPlayed.qml", track);
}
