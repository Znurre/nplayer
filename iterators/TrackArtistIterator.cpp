#include "TrackArtistIterator.h"

#include "entities/Track.h"
#include "entities/Artist.h"

TrackArtistIterator::TrackArtistIterator(Track *track)
	: m_track(track)
{

}

Artist *TrackArtistIterator::next(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);

	return requestHandler
		.get<Artist>("artist.getInfo"
			, as::artist = m_track->artist()
		);
}
