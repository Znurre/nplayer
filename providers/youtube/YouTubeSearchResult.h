#ifndef YOUTUBESEARCHRESULT_H
#define YOUTUBESEARCHRESULT_H

#include <QObject>
#include <QJsonSerializer>

#include "YouTubeSearchResultItem.h"

class YouTubeSearchResult : public QObject
{
	Q_OBJECT

	Q_PROPERTY(Array<YouTubeSearchResultItem *> items READ items WRITE setItems)

	public:
		Array<YouTubeSearchResultItem *> items() const;
		void setItems(const Array<YouTubeSearchResultItem *> &items);

	private:
		Array<YouTubeSearchResultItem *> m_items;
};

Q_DECLARE_METATYPE(YouTubeSearchResult *)

#endif // YOUTUBESEARCHRESULT_H
