#ifndef ARTISTTRACKITERATOR_H
#define ARTISTTRACKITERATOR_H

#include <QList>

#include "IIterator.h"

class Track;
class Artist;

class ArtistTrackIterator : public PagingIterator<Artist, Track>
{
	public:
		QList<Track *> fetchMore(Artist *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // ARTISTTRACKITERATOR_H
