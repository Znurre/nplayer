#include "AlbumTrackIterator.h"

#include "entities/Album.h"

AlbumTrackIterator::AlbumTrackIterator(Album *album)
	: m_album(album)
{

}

QList<Track *> AlbumTrackIterator::fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	Q_UNUSED(informationResourceRepository);
	Q_UNUSED(idGenerator);
	Q_UNUSED(page);

	return m_album->tracks();
}
