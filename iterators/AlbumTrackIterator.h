#ifndef ALBUMTRACKITERATOR_H
#define ALBUMTRACKITERATOR_H

#include "IIterator.h"

class Album;
class Track;

class AlbumTrackIterator : public PagingIterator<Album, Track>
{
	public:
		QList<Track *> fetchMore(Album *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // ALBUMTRACKITERATOR_H
