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

void AlbumRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(who);

	const QString &id = arguments.join(QChar::Space);

	InformationResourceRepository &informationResourceRepository = context.informationResourceRepository();
	Track *track = informationResourceRepository.get<Track>(id);

	if (track)
	{

	}
}
