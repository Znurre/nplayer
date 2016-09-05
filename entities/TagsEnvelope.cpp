#include "TagsEnvelope.h"

TagsEnvelope::TagsEnvelope()
{

}

Array<Tag *> TagsEnvelope::tags() const
{
	return m_tags;
}

void TagsEnvelope::setTags(const Array<Tag *> &tags)
{
	m_tags = tags;
}
