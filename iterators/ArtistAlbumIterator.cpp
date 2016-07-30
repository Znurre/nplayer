#include "ArtistAlbumIterator.h"
#include "RequestHandler.h"

#include "entities/Artist.h"
#include "entities/AlbumsEnvelope.h"

ArtistAlbumIterator::ArtistAlbumIterator(Artist *artist)
	: m_artist(artist)
{

}

QList<Album *> ArtistAlbumIterator::fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	AlbumsEnvelope *envelope = requestHandler
		.get<AlbumsEnvelope>("artist.getTopAlbums"
			, as::artist = m_artist->name()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->albums();
	}

	return QList<Album *>();
}
