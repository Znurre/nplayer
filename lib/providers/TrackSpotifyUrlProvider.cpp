#include "TrackSpotifyUrlProvider.h"

#include "entities/Track.h"

QString TrackSpotifyUrlProvider::buildUrl(Track *resource) const
{
	const QString &formattedTitle = resource->formattedTitle();
	const QString &url = QStringEx::format("https://api.spotify.com/v1/search?q=%1&type=track&limit=1", formattedTitle);

	return url;
}

SpotifySearchFragment<SpotifyTrack> *TrackSpotifyUrlProvider::getFragment(SpotifySearchResult &result) const
{
	return result.tracks();
}
