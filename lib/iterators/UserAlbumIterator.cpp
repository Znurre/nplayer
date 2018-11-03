#include "UserAlbumIterator.h"
#include "RequestHandler.h"

#include "entities/IUser.h"
#include "entities/AlbumsEnvelope.h"

QList<Album *> UserAlbumIterator::fetchMore(IUser *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	AlbumsEnvelope *envelope = requestHandler
		.get<AlbumsEnvelope>("user.getTopAlbums"
			, as::user = resource->user()
			, as::period = resource->period()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->albums();
	}

	return QList<Album *>();
}
