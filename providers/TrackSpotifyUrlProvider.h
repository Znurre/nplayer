#ifndef TRACKSPOTIFYURLPROVIDER_H
#define TRACKSPOTIFYURLPROVIDER_H

#include "SpotifyUrlProvider.h"

class TrackSpotifyUrlProvider : public SpotifyUrlProvider<Track, SpotifyTrack>
{
	protected:
		QString buildUrl(Track *resource) const override;

		SpotifySearchFragment<SpotifyTrack> *getFragment(SpotifySearchResult &result) const override;
};

#endif // TRACKSPOTIFYURLPROVIDER_H
