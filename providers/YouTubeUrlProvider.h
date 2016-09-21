#ifndef YOUTUBEURLPROVIDER_H
#define YOUTUBEURLPROVIDER_H

#include "IUrlProvider.h"

class Track;

class YouTubeUrlProvider : public UrlProvider<Track, IUrlProvider>
{
	public:
		QString url(Track *resource) const override;
};

#endif // YOUTUBEURLPROVIDER_H
