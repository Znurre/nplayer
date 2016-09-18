#ifndef URLREQUEST_H
#define URLREQUEST_H

#include "IRequest.h"
#include "InformationResourceRepository.h"
#include "IInformationResource.h"
#include "RequestInvocationContext.h"
#include "RequestResponse.h"
#include "IUrlProvider.h"

#include "entities/UrlContext.h"

template<class TProvider>
class UrlRequest : public IRequest
{
	public:
		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override
		{
			Q_UNUSED(who);

			const QString &id = arguments.join(QChar::Space);

			InformationResourceRepository &repository = context.informationResourceRepository();
			IInformationResource *resource = repository.get(id);

			if (resource)
			{
				IUrlProvider *provider = resource->provider<TProvider>();

				if (provider)
				{
					UrlContext *context = new UrlContext(provider, resource);

					return RequestResponse("templates/Url.qml", context);
				}
			}

			return RequestResponse();
		}

};

#endif // URLREQUEST_H
