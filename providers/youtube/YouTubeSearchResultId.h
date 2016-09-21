#ifndef YOUTUBESEARCHRESULTID_H
#define YOUTUBESEARCHRESULTID_H

#include <QObject>

class YouTubeSearchResultId : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString videoId READ videoId WRITE setVideoId)

	public:
		Q_INVOKABLE YouTubeSearchResultId() = default;

		QString videoId() const;
		void setVideoId(const QString &videoId);

	private:
		QString m_videoId;
};

Q_DECLARE_METATYPE(YouTubeSearchResultId *)

#endif // YOUTUBESEARCHRESULTID_H
