#include "SpotifySearchResult.h"

SpotifySearchResult::SpotifySearchResult()
{

}

SpotifyTrackSearchFragment *SpotifySearchResult::tracks() const
{
	return m_tracks;
}

void SpotifySearchResult::setTracks(SpotifyTrackSearchFragment *tracks)
{
	m_tracks = tracks;
}
