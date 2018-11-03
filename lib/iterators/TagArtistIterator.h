#ifndef TAGARTISTITERATOR_H
#define TAGARTISTITERATOR_H

#include "entities/Artist.h"
#include "entities/Tag.h"

class TagArtistIterator : public PagingIterator<Tag, Artist>
{
	public:
		QList<Artist *> fetchMore(Tag *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // TAGARTISTITERATOR_H
