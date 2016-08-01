#ifndef TRACKALBUMITERATOR_H
#define TRACKALBUMITERATOR_H

#include "IIterator.h"

#include "entities/Album.h"

class Track;

class TrackAlbumIterator : public IIterator<Album>
{
	public:
		TrackAlbumIterator(Track *track);

		Album *next(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator) override;

	private:
		Track *m_track;
};

#endif // TRACKALBUMITERATOR_H
