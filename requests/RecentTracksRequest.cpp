#include "RecentTracksRequest.h"
#include "RequestInvocationContext.h"
#include "RequestHandler.h"
#include "IdGenerator.h"
#include "UserMapper.h"

#include "entities/TracksEnvelope.h"

Track *RecentTracksRequest::getRecentTrack(const QString &nick, const RequestInvocationContext &context, TrackPredicate predicate) const
{
	InformationResourceRepository &repository = context.informationResourceRepository();
	IdGenerator &idGenerator = context.idGenerator();
	UserMapper &userMapper = context.userMapper();

	const RequestHandler requestHandler(repository, idGenerator);
	const TracksEnvelope *recentTracks = requestHandler
		.get<TracksEnvelope>("user.getRecentTracks"
			, as::limit = 1
			, as::user = userMapper.map(nick)
			, as::nick = nick
		);

	if (recentTracks)
	{
		for (Track *track : recentTracks->tracks())
		{
			if (predicate(track))
			{
				return track;
			}
		}
	}

	return nullptr;
}
