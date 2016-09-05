#include "TagRequest.h"
#include "RequestHandler.h"
#include "RequestInvocationContext.h"
#include "RequestResponse.h"

#include "entities/Tag.h"

QString TagRequest::trigger() const
{
	return ".tag";
}

RequestResponse TagRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(who);

	const QString &id = arguments.join(QChar::Space);

	InformationResourceRepository &repository = context.informationResourceRepository();
	IdGenerator &idGenerator = context.idGenerator();

	IInformationResource *resource = repository.get(id);

	if (resource)
	{
		IIterator<Tag> *iterator = resource->iterator<Tag>();

		if (iterator)
		{
			Tag *tag = iterator->next(resource, repository, idGenerator);

			if (tag)
			{
				return RequestResponse("templates/Tag.qml", tag);
			}

			return RequestResponse("templates/NoMoreData.qml", nullptr);
		}
	}
	else
	{
		RequestHandler requestHandler(repository, idGenerator);

		Tag *tag = requestHandler
			.get<Tag>("tag.getInfo"
				, as::tag = arguments.join(QChar::Space)
			);

		if (tag)
		{
			return RequestResponse("templates/Tag.qml", tag);
		}
	}

	return RequestResponse();
}
