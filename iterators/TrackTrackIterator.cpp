#include "TrackTrackIterator.h"
#include "RequestHandler.h"

#include "entities/TracksEnvelope.h"
#include "entities/Track.h"

QList<Track *> TrackTrackIterator::fetchMore(Track *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	TracksEnvelope *envelope = requestHandler
		.get<TracksEnvelope>("track.getSimilar"
			, as::artist = resource->artist()
			, as::track = resource->name()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->tracks();
	}

	return QList<Track *>();
}
