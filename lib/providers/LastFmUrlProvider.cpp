#include "LastFmUrlProvider.h"

QString LastFmUrlProvider::url(IInformationResource *resource) const
{
	return resource->url();
}
