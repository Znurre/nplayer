#include "TagArtistIterator.h"
#include "RequestHandler.h"

#include "entities/ArtistsEnvelope.h"

QList<Artist *> TagArtistIterator::fetchMore(Tag *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	ArtistsEnvelope *envelope = requestHandler
		.get<ArtistsEnvelope>("tag.getTopArtists"
			, as::tag = resource->name()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->artists();
	}

	return QList<Artist *>();
}
