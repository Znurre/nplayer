#ifndef SPOTIFYURLREQUEST_H
#define SPOTIFYURLREQUEST_H

#include "UrlRequest.h"

#include "providers/SpotifyUrlProvider.h"

class SpotifyUrlRequest : public UrlRequest<ISpotifyUrlProvider>
{
	public:
		QString trigger() const override;
};

#endif // SPOTIFYURLREQUEST_H
