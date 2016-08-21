#include "ArtistRequest.h"
#include "RequestHandler.h"
#include "RequestInvocationContext.h"
#include "RequestResponse.h"
#include "InformationResourceRepository.h"

#include "entities/Artist.h"

QString ArtistRequest::trigger() const
{
	return ".artist";
}

RequestResponse ArtistRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	const QString &id = arguments.join(QChar::Space);

	InformationResourceRepository &repository = context.informationResourceRepository();
	IdGenerator &idGenerator = context.idGenerator();

	IInformationResource *resource = repository.get(id);

	if (resource)
	{
		IIterator<Artist> *iterator = resource->iterator<Artist>();

		if (iterator)
		{
			Artist *artist = iterator->next(repository, idGenerator);

			if (artist)
			{
				return RequestResponse("templates/Artist.qml", artist);
			}

			return RequestResponse("templates/NoMoreData.qml", nullptr);
		}
	}
	else
	{
		RequestHandler requestHandler(repository, idGenerator);

		Artist *artist = requestHandler
			.get<Artist>("artist.getInfo"
				, as::artist = arguments.join(QChar::Space)
				, as::username = who
			);

		if (artist)
		{
			return RequestResponse("templates/Artist.qml", artist);
		}
	}

	return RequestResponse();
}
