#ifndef TRACKARTISTITERATOR_H
#define TRACKARTISTITERATOR_H

#include "IIterator.h"

class Track;
class Artist;

class TrackArtistIterator : public IteratorBase<Track, Artist>
{
	public:
		Artist *next(Track *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator) override;
};

#endif // TRACKARTISTITERATOR_H
