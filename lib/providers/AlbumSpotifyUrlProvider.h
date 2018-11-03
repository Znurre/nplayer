#ifndef ALBUMSPOTIFYURLPROVIDER_H
#define ALBUMSPOTIFYURLPROVIDER_H

#include "SpotifyUrlProvider.h"

class Album;

class AlbumSpotifyUrlProvider : public SpotifyUrlProvider<Album, SpotifyAlbum>
{
	protected:
		QString buildUrl(Album *resource) const override;

		SpotifySearchFragment<SpotifyAlbum> *getFragment(SpotifySearchResult &result) const override;
};

#endif // ALBUMSPOTIFYURLPROVIDER_H
