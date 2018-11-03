#include "Tags.h"

QList<QObject *> Tags::tags() const
{
	return m_tags;
}

void Tags::setTags(const QList<QObject *> &tags)
{
	m_tags = tags;
}
