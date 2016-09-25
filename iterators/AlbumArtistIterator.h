#ifndef ALBUMARTISTITERATOR_H
#define ALBUMARTISTITERATOR_H

#include "IIterator.h"

class Album;
class Artist;

class AlbumArtistIterator : public IteratorBase<Album, Artist>
{
	public:
		Artist *next(Album *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator) override;
};

#endif // ALBUMARTISTITERATOR_H
