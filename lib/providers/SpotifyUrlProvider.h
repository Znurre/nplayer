#ifndef SPOTIFYURLPROVIDER_H
#define SPOTIFYURLPROVIDER_H

#include <QEventLoop>
#include <QJsonSerializer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "IUrlProvider.h"
#include "QStringEx.h"

#include "spotify/SpotifySearchResult.h"

class ISpotifyUrlProvider : public IUrlProvider
{
	// Marker interface
};

template<class TResource, class TResult>
class SpotifyUrlProvider : public UrlProvider<TResource, ISpotifyUrlProvider>
{
	public:
		QString url(TResource *resource) const override
		{
			const QString &url = buildUrl(resource);
			const QNetworkRequest request(url);

			QEventLoop eventLoop;
			QNetworkAccessManager network;
			QJsonSerializer serializer;

			QNetworkReply *reply = network.get(request);

			QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);

			eventLoop.exec();

			SpotifySearchResult result;

			serializer.deserialize(reply, &result);

			SpotifySearchFragment<TResult> *fragment = getFragment(result);

			if (fragment)
			{
				for (TResult *track : fragment->items())
				{
					SpotifyExternalUrl *external = track->externalUrls();

					if (external)
					{
						return external->spotify();
					}
				}
			}

			return QString();
		}

	protected:
		virtual QString buildUrl(TResource *resource) const = 0;

		virtual SpotifySearchFragment<TResult> *getFragment(SpotifySearchResult &result) const = 0;
};

#endif // SPOTIFYURLPROVIDER_H
