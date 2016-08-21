#include "ArtistArtistIterator.h"
#include "RequestHandler.h"

#include "entities/ArtistsEnvelope.h"
#include "entities/Artist.h"

ArtistArtistIterator::ArtistArtistIterator(Artist *artist)
	: m_artist(artist)
{

}

QList<Artist *> ArtistArtistIterator::fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	ArtistsEnvelope *envelope = requestHandler
		.get<ArtistsEnvelope>("artist.getSimilar"
			, as::artist = m_artist->name()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->artists();
	}

	return QList<Artist *>();
}
