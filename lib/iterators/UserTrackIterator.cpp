#include "UserTrackIterator.h"
#include "RequestHandler.h"

#include "entities/User.h"
#include "entities/Track.h"
#include "entities/TracksEnvelope.h"

QList<Track *> UserTrackIterator::fetchMore(IUser *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	TracksEnvelope *envelope = requestHandler
		.get<TracksEnvelope>("user.getTopTracks"
			, as::user = resource->user()
			, as::period = resource->period()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->tracks();
	}

	return QList<Track *>();
}
