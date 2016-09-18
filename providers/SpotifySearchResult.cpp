#include "SpotifySearchResult.h"

SpotifySearchResult::SpotifySearchResult()
	: m_tracks(nullptr)
	, m_artists(nullptr)
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

SpotifyArtistSearchFragment *SpotifySearchResult::artists() const
{
	return m_artists;
}

void SpotifySearchResult::setArtists(SpotifyArtistSearchFragment *artists)
{
	m_artists = artists;
}

SpotifyAlbumSearchFragment *SpotifySearchResult::albums() const
{
	return m_albums;
}

void SpotifySearchResult::setAlbums(SpotifyAlbumSearchFragment *albums)
{
	m_albums = albums;
}
