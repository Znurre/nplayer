#include "AlbumSpotifyUrlProvider.h"

#include "entities/Album.h"

QString AlbumSpotifyUrlProvider::buildUrl(Album *resource) const
{
	const QString &artist = resource->artist();
	const QString &name = resource->name();

	return QStringEx::format("https://api.spotify.com/v1/search?q=%1 - %2&type=album&limit=1", artist, name);
}

SpotifySearchFragment<SpotifyAlbum> *AlbumSpotifyUrlProvider::getFragment(SpotifySearchResult &result) const
{
	return result.albums();
}
