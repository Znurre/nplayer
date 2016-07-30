#include "TracksEnvelope.h"

TracksEnvelope::TracksEnvelope()
{

}

void TracksEnvelope::setTracks(const Array<Track *> &tracks)
{
	m_tracks = tracks;
}

Array<Track *> TracksEnvelope::tracks() const
{
	return m_tracks;
}
