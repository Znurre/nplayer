#ifndef TAGSENVELOPE_H
#define TAGSENVELOPE_H

#include <QObject>

#include "Tag.h"

class TagsEnvelope : public QObject
{
	Q_OBJECT

	Q_PROPERTY(Array<Tag *> tags READ tags WRITE setTags)

	public:
		Q_INVOKABLE TagsEnvelope();

		Array<Tag *> tags() const;
		void setTags(const Array<Tag *> &tags);

	private:
		Array<Tag *> m_tags;
};

#endif // TAGSENVELOPE_H
