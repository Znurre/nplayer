#ifndef TRACKTRACKITERATOR_H
#define TRACKTRACKITERATOR_H

#include "IIterator.h"

class Track;

class TrackTrackIterator : public IteratorBase<Track>
{
	public:
		TrackTrackIterator(Track *track);

		QList<Track *> fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;

	private:
		Track *m_track;
};

#endif // TRACKTRACKITERATOR_H
