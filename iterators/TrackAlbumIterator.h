#ifndef TRACKALBUMITERATOR_H
#define TRACKALBUMITERATOR_H

#include "IIterator.h"

#include "entities/Album.h"

class Track;

class TrackAlbumIterator : public IteratorBase<Track, Album>
{
	public:
		Album *next(Track *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator) override;
};

#endif // TRACKALBUMITERATOR_H
