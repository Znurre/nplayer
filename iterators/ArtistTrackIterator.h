#ifndef ARTISTTRACKITERATOR_H
#define ARTISTTRACKITERATOR_H

#include <QList>

#include "IIterator.h"

class Track;
class Artist;

class ArtistTrackIterator : public IteratorBase<Track>
{
	public:
		ArtistTrackIterator(Artist *artist);

		QList<Track *> fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;

	private:
		Artist *m_artist;
};

#endif // ARTISTTRACKITERATOR_H
