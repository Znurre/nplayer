#include "UserTagIterator.h"

#include "entities/User.h"
#include "entities/Tag.h"
#include "entities/TagsEnvelope.h"

QList<Tag *> UserTagIterator::fetchMore(User *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page)
{
	RequestHandler requestHandler(informationResourceRepository, idGenerator);
	TagsEnvelope *envelope = requestHandler
		.get<TagsEnvelope>("user.getTopTags"
			, as::user = resource->user()
			, as::limit = 10
			, as::page = page
		);

	if (envelope)
	{
		return envelope->tags();
	}

	return QList<Tag *>();
}
