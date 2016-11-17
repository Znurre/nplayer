#include "TracksEnvelope.h"

Array<Track *> TracksEnvelope::tracks() const
{
	return m_tracks;
}

void TracksEnvelope::setTracks(const Array<Track *> &tracks)
{
	m_tracks = tracks;
}

bool TracksEnvelope::isValid() const
{
	return !m_tracks.isEmpty();
}
