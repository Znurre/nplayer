#ifndef ARTISTARTISTITERATOR_H
#define ARTISTARTISTITERATOR_H

#include "IIterator.h"

class Artist;

class ArtistArtistIterator : public IteratorBase<Artist>
{
	public:
		ArtistArtistIterator(Artist *artist);

		QList<Artist *> fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;

	private:
		Artist *m_artist;
};

#endif // ARTISTARTISTITERATOR_H
