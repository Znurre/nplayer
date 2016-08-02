#include "TagTrackIterator.h"
#include "RequestHandler.h"

#include "entities/Tag.h"
#include "entities/TracksEnvelope.h"

TagTrackIterator::TagTrackIterator(Tag *tag)
	: m_tag(tag)
{

}

QList<Track *> TagTrackIterator::fetchMore(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	TracksEnvelope *envelope = requestHandler
		.get<TracksEnvelope>("tag.getTopTracks"
			, as::tag = m_tag->name()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->tracks();
	}

	return QList<Track *>();
}

