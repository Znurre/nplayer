#ifndef YOUTUBEURLREQUEST_H
#define YOUTUBEURLREQUEST_H

#include "UrlRequest.h"

#include "providers/YouTubeUrlProvider.h"

class YouTubeUrlRequest : public UrlRequest<YouTubeUrlProvider>
{
	public:
		QString trigger() const override;
};

#endif // YOUTUBEURLREQUEST_H
