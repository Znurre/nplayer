#include "TagsEnvelope.h"

Array<Tag *> TagsEnvelope::tags() const
{
	return m_tags;
}

void TagsEnvelope::setTags(const Array<Tag *> &tags)
{
	m_tags = tags;
}

bool TagsEnvelope::isValid() const
{
	return !m_tags.isEmpty();
}
