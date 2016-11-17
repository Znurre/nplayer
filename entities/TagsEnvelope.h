#ifndef TAGSENVELOPE_H
#define TAGSENVELOPE_H

#include <QObject>

#include "Tag.h"

class TagsEnvelope
	: public QObject
	, public IVerifiable
{
	Q_OBJECT

	Q_PROPERTY(Array<Tag *> tags READ tags WRITE setTags)

	public:
		Q_INVOKABLE TagsEnvelope() = default;

		Array<Tag *> tags() const;
		void setTags(const Array<Tag *> &tags);

		bool isValid() const override;

	private:
		Array<Tag *> m_tags;
};

#endif // TAGSENVELOPE_H
