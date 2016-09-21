#include <QNetworkRequest>

#include "YouTubeUrlProvider.h"
#include "QStringEx.h"

#include "entities/Track.h"

#include "youtube/YouTubeSearchResult.h"

const QString URL = "https://www.googleapis.com/youtube/v3/search?part=snippet&type=video&maxResults=1&key=AIzaSyCGicONr8DIpSKKjKeV4flDcsU3Q_EKi_c&q=%1";

QString YouTubeUrlProvider::url(Track *resource) const
{
	const QString &formattedTitle = resource->formattedTitle();
	const QString &url = QStringEx::format(URL, formattedTitle);

	const QNetworkRequest request(url);

	QEventLoop eventLoop;
	QNetworkAccessManager network;
	QJsonSerializer serializer;

	QNetworkReply *reply = network.get(request);

	QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);

	eventLoop.exec();

	YouTubeSearchResult result;

	serializer.deserialize(reply, &result);

	for (YouTubeSearchResultItem *item : result.items())
	{
		YouTubeSearchResultId *id = item->id();

		if (id)
		{
			const QString &videoId = id->videoId();
			const QString &url = QStringEx::format("https://www.youtube.com/watch?v=%1", videoId);

			return url;
		}
	}

	return QString();
}
