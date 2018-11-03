#ifndef TRACKTRACKITERATOR_H
#define TRACKTRACKITERATOR_H

#include "IIterator.h"

class Track;

class TrackTrackIterator : public PagingIterator<Track, Track>
{
	public:
		QList<Track *> fetchMore(Track *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // TRACKTRACKITERATOR_H
