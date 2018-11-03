#include "ArtistSpotifyUrlProvider.h"

#include "entities/Artist.h"

QString ArtistSpotifyUrlProvider::buildUrl(Artist *resource) const
{
	const QString &name = resource->name();
	const QString &url = QStringEx::format("https://api.spotify.com/v1/search?q=%1&type=artist&limit=1", name);

	return url;
}

SpotifySearchFragment<SpotifyArtist> *ArtistSpotifyUrlProvider::getFragment(SpotifySearchResult &result) const
{
	return result.artists();
}
