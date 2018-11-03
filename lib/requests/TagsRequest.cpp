#include "TagsRequest.h"
#include "RequestInvocationContext.h"

#include "entities/Tag.h"
#include "entities/Tags.h"

QString TagsRequest::trigger() const
{
	return ".tags";
}

RequestResponse TagsRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
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
			QList<QObject *> tags;

			for (int i = 0; i < 10; i++)
			{
				Tag *tag = iterator->next(resource, repository, idGenerator);

				if (!tag)
				{
					if (!i)
					{
						return RequestResponse("templates/NoMoreData.qml", nullptr);
					}

					break;
				}
				else
				{
					tags << tag;
				}
			}

			Tags *envelope = new Tags();
			envelope->setTags(tags);

			return RequestResponse("templates/Tags.qml", envelope);
		}
	}

	return RequestResponse();
}
