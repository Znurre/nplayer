#ifndef LASTFMURLREQUEST_H
#define LASTFMURLREQUEST_H

#include "UrlRequest.h"

#include "providers/LastFmUrlProvider.h"

class LastFmUrlRequest : public UrlRequest<LastFmUrlProvider>
{
	public:
		QString trigger() const override;
};

#endif // LASTFMURLREQUEST_H
