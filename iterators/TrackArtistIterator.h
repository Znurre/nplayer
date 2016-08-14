#ifndef TRACKARTISTITERATOR_H
#define TRACKARTISTITERATOR_H

#include "IIterator.h"

class Track;
class Artist;

class TrackArtistIterator : public IIterator<Artist>
{
	public:
		TrackArtistIterator(Track *track);

		Artist *next(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator) override;

	private:
		Track *m_track;
};

#endif // TRACKARTISTITERATOR_H
