#include "AlbumRequest.h"
#include "RequestInvocationContext.h"
#include "InformationResourceRepository.h"

#include "entities/Album.h"

AlbumRequest::AlbumRequest()
{

}

QString AlbumRequest::trigger() const
{
	return ".album";
}

RequestResponse AlbumRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(who);

	const QString &id = arguments.join(QChar::Space);

	InformationResourceRepository &repository = context.informationResourceRepository();
	IdGenerator &idGenerator = context.idGenerator();

	IInformationResource *resource = repository.get(id);

	if (resource)
	{
		IIterator<Album> *iterator = resource->iterator<Album>();

		if (iterator)
		{
			Album *album = iterator->next(repository, idGenerator);

			if (album)
			{
				return RequestResponse("templates/Album.qml", album);
			}

			return RequestResponse("templates/NoMoreData.qml", nullptr);
		}
	}

	return RequestResponse();
}
