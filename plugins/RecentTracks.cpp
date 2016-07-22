#include "RecentTracks.h"

RecentTracks::RecentTracks()
{

}

void RecentTracks::setTracks(const Array<Track *> &tracks)
{
	m_tracks = tracks;
}

Array<Track *> RecentTracks::tracks() const
{
	return m_tracks;
}
