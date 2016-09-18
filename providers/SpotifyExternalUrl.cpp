#include "SpotifyExternalUrl.h"

QString SpotifyExternalUrl::spotify() const
{
	return m_spotify;
}

void SpotifyExternalUrl::setSpotify(const QString &spotify)
{
	m_spotify = spotify;
}
