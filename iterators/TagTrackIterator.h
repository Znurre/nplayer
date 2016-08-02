#ifndef TAGTRACKITERATOR_H
#define TAGTRACKITERATOR_H

#include "IIterator.h"

class Tag;
class Track;

class TagTrackIterator : public IteratorBase<Track>
{
	public:
		TagTrackIterator(Tag *tag);

		QList<Track *> fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;

	private:
		Tag *m_tag;
};

#endif // TAGTRACKITERATOR_H
