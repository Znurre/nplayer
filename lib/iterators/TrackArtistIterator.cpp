#include "TrackArtistIterator.h"

#include "entities/Track.h"
#include "entities/Artist.h"

QList<Artist *> TrackArtistIterator::fetchMore(Track *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	QList<Artist *> artists;

	if (page <= 1)
	{
		RequestHandler requestHandler(informationResourceRepository, idGenerator);

		Artist *artist = requestHandler
			.get<Artist>("artist.getInfo"
				, as::artist = resource->artist()
			);

		if (artist)
		{
			artists << artist;
		}
	}

	return artists;
}
