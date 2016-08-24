#include "TrackAlbumIterator.h"

#include "entities/Track.h"
#include "entities/Album.h"

Album *TrackAlbumIterator::next(Track *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);

	return requestHandler
		.get<Album>("album.getInfo"
			, as::required(as::album) = resource->album()
			, as::artist = resource->artist()
			, as::user = resource->user()
		);
}
