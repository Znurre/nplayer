#ifndef TRACKARTISTITERATOR_H
#define TRACKARTISTITERATOR_H

#include "IIterator.h"

class Track;
class Artist;

class TrackArtistIterator : public PagingIterator<Track, Artist>
{
	public:
		QList<Artist *> fetchMore(Track *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // TRACKARTISTITERATOR_H
