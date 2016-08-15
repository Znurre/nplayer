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
			, as::required(as::album) = m_track->album()
			, as::artist = m_track->artist()
			, as::user = m_track->user()
		);

	return nullptr;
}
