#ifndef ARTISTARTISTITERATOR_H
#define ARTISTARTISTITERATOR_H

#include "IIterator.h"

class Artist;

class ArtistArtistIterator : public PagingIterator<Artist, Artist>
{
	public:
		QList<Artist *> fetchMore(Artist *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // ARTISTARTISTITERATOR_H
