#include "TrackArtistIterator.h"

#include "entities/Track.h"
#include "entities/Artist.h"

Artist *TrackArtistIterator::next(Track *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);

	return requestHandler
		.get<Artist>("artist.getInfo"
			, as::artist = resource->artist()
		);
}
