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

	InformationResourceRepository &repository = context.informationResourceRepository();
	IdGenerator &idGenerator = context.idGenerator();

	RequestHandler requestHandler(repository, idGenerator);

	Tag *artist = requestHandler
		.get<Tag>("tag.getInfo"
			, as::tag = arguments.join(QChar::Space)
		);

	if (artist)
	{
		return RequestResponse("templates/Tag.qml", artist);
	}

	return RequestResponse();
}
