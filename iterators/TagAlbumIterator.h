#ifndef TAGALBUMITERATOR_H
#define TAGALBUMITERATOR_H

#include "IIterator.h"

class Tag;
class Album;

class TagAlbumIterator : public PagingIterator<Tag, Album>
{
	public:
		QList<Album *> fetchMore(Tag *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // TAGALBUMITERATOR_H
