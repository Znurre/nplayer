#include "AlbumRequest.h"
#include "RequestInvocationContext.h"
#include "InformationResourceRepository.h"

#include "entities/Track.h"

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
	Track *track = repository.get<Track>(id);

	if (track)
	{
		return RequestResponse("templates/Album.qml", track);
	}

	return RequestResponse();
}
