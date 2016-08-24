#include "AlbumTrackIterator.h"

#include "entities/Album.h"

QList<Track *> AlbumTrackIterator::fetchMore(Album *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	Q_UNUSED(informationResourceRepository);
	Q_UNUSED(idGenerator);
	Q_UNUSED(page);

	return resource->tracks();
}
