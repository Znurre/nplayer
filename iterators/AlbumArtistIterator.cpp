#include "AlbumArtistIterator.h"
#include "RequestHandler.h"

#include "entities/Artist.h"
#include "entities/Album.h"

Artist *AlbumArtistIterator::next(Album *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);

	return requestHandler
		.get<Artist>("artist.getInfo"
			, as::artist = resource->artist()
			, as::username = resource->user()
		);
}
