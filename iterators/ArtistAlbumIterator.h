#ifndef ARTISTALBUMITERATOR_H
#define ARTISTALBUMITERATOR_H

#include "IIterator.h"

class Album;
class Artist;

class ArtistAlbumIterator : public IteratorBase<Album>
{
	public:
		ArtistAlbumIterator(Artist *artist);

		QList<Album *> fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;

	private:
		Artist *m_artist;
};

#endif // ARTISTALBUMITERATOR_H
