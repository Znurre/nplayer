#include "TagTrackIterator.h"
#include "RequestHandler.h"

#include "entities/Tag.h"
#include "entities/TracksEnvelope.h"

QList<Track *> TagTrackIterator::fetchMore(Tag *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	TracksEnvelope *envelope = requestHandler
		.get<TracksEnvelope>("tag.getTopTracks"
			, as::tag = resource->name()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->tracks();
	}

	return QList<Track *>();
}

