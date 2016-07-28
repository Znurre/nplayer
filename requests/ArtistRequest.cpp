#include "ArtistRequest.h"
#include "RequestHandler.h"
#include "RequestInvocationContext.h"
#include "RequestResponse.h"

#include "entities/Artist.h"

QString ArtistRequest::trigger() const
{
	return ".artist";
}

RequestResponse ArtistRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	InformationResourceRepository &repository = context.informationResourceRepository();
	IdGenerator &idGenerator = context.idGenerator();

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

	return RequestResponse();
}
