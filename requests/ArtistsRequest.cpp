#include "ArtistsRequest.h"
#include "RequestInvocationContext.h"
#include "InformationResourceRepository.h"
#include "IdGenerator.h"

#include "entities/Artist.h"
#include "entities/Artists.h"

QString ArtistsRequest::trigger() const
{
	return ".artists";
}

RequestResponse ArtistsRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(who);

	const QString &id = arguments.join(QChar::Space);

	InformationResourceRepository &repository = context.informationResourceRepository();
	IdGenerator &idGenerator = context.idGenerator();

	IInformationResource *resource = repository.get(id);

	if (resource)
	{
		IIterator<Artist> *iterator = resource->iterator<Artist>();

		if (iterator)
		{
			Array<QString> artists;

			for (int i = 0; i < 10; i++)
			{
				Artist *artist = iterator->next(resource, repository, idGenerator);

				if (!artist)
				{
					if (!i)
					{
						return RequestResponse("templates/NoMoreData.qml", nullptr);
					}

					break;
				}
				else
				{
					artists << artist->name();
				}
			}

			Artists *envelope = new Artists();
			envelope->setArtists(artists);

			return RequestResponse("templates/Artists.qml", envelope);
		}
	}

	return RequestResponse();
}
