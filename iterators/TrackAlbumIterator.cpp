#include "TrackAlbumIterator.h"

#include "entities/Track.h"
#include "entities/Album.h"

TrackAlbumIterator::TrackAlbumIterator(Track *track)
	: m_track(track)
{

}

Album *TrackAlbumIterator::next(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);

	return requestHandler
		.get<Album>("album.getInfo"
			, as::artist = m_track->artist()
			, as::album = m_track->album()
		);
}
