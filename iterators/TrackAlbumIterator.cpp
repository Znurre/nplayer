#include "TrackAlbumIterator.h"

#include "entities/Track.h"

TrackAlbumIterator::TrackAlbumIterator(Track *track)
	: m_track(track)
{

}

Album *TrackAlbumIterator::next(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator)
{
	Q_UNUSED(informationResourceRepository);
	Q_UNUSED(idGenerator);

	if (m_track)
	{
		const QString &album = m_track->album();

		m_album.setName(album);

		if (m_album)
		{
			return &m_album;
		}
	}

	return nullptr;
}
