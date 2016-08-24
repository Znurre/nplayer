#include "ArtistArtistIterator.h"
#include "RequestHandler.h"

#include "entities/ArtistsEnvelope.h"
#include "entities/Artist.h"

QList<Artist *> ArtistArtistIterator::fetchMore(Artist *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	ArtistsEnvelope *envelope = requestHandler
		.get<ArtistsEnvelope>("artist.getSimilar"
			, as::artist = resource->name()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->artists();
	}

	return QList<Artist *>();
}
