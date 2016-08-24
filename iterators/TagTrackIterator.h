#ifndef TAGTRACKITERATOR_H
#define TAGTRACKITERATOR_H

#include "IIterator.h"

class Tag;
class Track;

class TagTrackIterator : public PagingIterator<Tag, Track>
{
	public:
		QList<Track *> fetchMore(Tag *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // TAGTRACKITERATOR_H
