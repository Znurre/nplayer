#ifndef LASTFMURLPROVIDER_H
#define LASTFMURLPROVIDER_H

#include "IUrlProvider.h"
#include "IInformationResource.h"

class LastFmUrlProvider : public IUrlProvider
{
	public:
		QString url(IInformationResource *resource) const override;
};

#endif // LASTFMURLPROVIDER_H
