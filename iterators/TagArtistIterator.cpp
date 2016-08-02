#include "TagArtistIterator.h"
#include "RequestHandler.h"

#include "entities/ArtistsEnvelope.h"

TagArtistIterator::TagArtistIterator(Tag *tag)
	: m_tag(tag)
{

}

QList<Artist *> TagArtistIterator::fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	ArtistsEnvelope *envelope = requestHandler
		.get<ArtistsEnvelope>("tag.getTopArtists"
			, as::tag = m_tag->name()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->artists();
	}

	return QList<Artist *>();
}
