#include "UserArtistIterator.h"
#include "RequestHandler.h"

#include "entities/User.h"
#include "entities/ArtistsEnvelope.h"

QList<Artist *> UserArtistIterator::fetchMore(IUser *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	ArtistsEnvelope *envelope = requestHandler
		.get<ArtistsEnvelope>("user.getTopArtists"
			, as::user = resource->user()
			, as::period = resource->period()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->artists();
	}

	return QList<Artist *>();
}
