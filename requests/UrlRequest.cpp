#include "UrlRequest.h"
#include "InformationResourceRepository.h"
#include "RequestInvocationContext.h"

QString UrlRequest::trigger() const
{
	return ".fm";
}

RequestResponse UrlRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(who);

	const QString &id = arguments.join(QChar::Space);

	InformationResourceRepository &repository = context.informationResourceRepository();
	IInformationResource *resource = repository.get(id);

	if (resource)
	{
		return RequestResponse("templates/Url.qml", resource);
	}

	return RequestResponse();
}
