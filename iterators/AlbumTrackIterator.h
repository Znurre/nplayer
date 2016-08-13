#ifndef ALBUMTRACKITERATOR_H
#define ALBUMTRACKITERATOR_H

#include "IIterator.h"

class Album;
class Track;

class AlbumTrackIterator : public IteratorBase<Track>
{
	public:
		AlbumTrackIterator(Album *album);

		QList<Track *> fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;

	private:
		Album *m_album;
};

#endif // ALBUMTRACKITERATOR_H
