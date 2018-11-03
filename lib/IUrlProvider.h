#ifndef IURLPROVIDER_H
#define IURLPROVIDER_H

#include <QString>
#include <QObject>

class IInformationResource;

class IUrlProvider
{
	public:
		virtual QString url(IInformationResource *resource) const = 0;
};

template<class TResource, class TProvider>
class UrlProvider : public TProvider
{
	public:
		QString url(IInformationResource *resource) const override
		{
			return url((TResource *)resource);
		}

	protected:
		virtual QString url(TResource *resource) const = 0;
};

#endif // IURLPROVIDER_H
