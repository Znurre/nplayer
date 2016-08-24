#ifndef ARTISTALBUMITERATOR_H
#define ARTISTALBUMITERATOR_H

#include "IIterator.h"

class Album;
class Artist;

class ArtistAlbumIterator : public PagingIterator<Artist, Album>
{
	public:
		QList<Album *> fetchMore(Artist *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // ARTISTALBUMITERATOR_H
