#include "TagAlbumIterator.h"

#include "entities/Tag.h"
#include "entities/AlbumsEnvelope.h"

QList<Album *> TagAlbumIterator::fetchMore(Tag *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	AlbumsEnvelope *envelope = requestHandler
		.get<AlbumsEnvelope>("tag.getTopAlbums"
			, as::tag = resource->name()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->albums();
	}

	return QList<Album *>();
}
