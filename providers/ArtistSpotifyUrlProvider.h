#ifndef ARTISTSPOTIFYURLPROVIDER_H
#define ARTISTSPOTIFYURLPROVIDER_H

#include "SpotifyUrlProvider.h"

class Artist;

class ArtistSpotifyUrlProvider : public SpotifyUrlProvider<Artist, SpotifyArtist>
{
	protected:
		QString buildUrl(Artist *resource) const override;

		SpotifySearchFragment<SpotifyArtist> *getFragment(SpotifySearchResult &result) const override;
};

#endif // ARTISTSPOTIFYURLPROVIDER_H
