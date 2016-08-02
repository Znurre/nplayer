#ifndef TAGARTISTITERATOR_H
#define TAGARTISTITERATOR_H

#include "entities/Artist.h"
#include "entities/Tag.h"

class TagArtistIterator : public IteratorBase<Artist>
{
	public:
		TagArtistIterator(Tag *tag);

		QList<Artist *> fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;

	private:
		Tag *m_tag;
};

#endif // TAGARTISTITERATOR_H
