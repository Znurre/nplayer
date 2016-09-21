#ifndef YOUTUBESEARCHRESULTITEM_H
#define YOUTUBESEARCHRESULTITEM_H

#include <QObject>
#include <QJsonSerializer>

#include "YouTubeSearchResultId.h"

class YouTubeSearchResultItem : public QObject
{
	Q_OBJECT

	Q_PROPERTY(YouTubeSearchResultId *id READ id WRITE setId)

	public:
		Q_INVOKABLE YouTubeSearchResultItem();

		YouTubeSearchResultId *id() const;
		void setId(YouTubeSearchResultId *id);

	private:
		YouTubeSearchResultId *m_id;
};

Q_DECLARE_METATYPE(YouTubeSearchResultItem *)
Q_DECLARE_METATYPE(Array<YouTubeSearchResultItem *>)

#endif // YOUTUBESEARCHRESULTITEM_H
