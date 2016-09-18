#ifndef SPOTIFYTRACK_H
#define SPOTIFYTRACK_H

#include <QObject>

#include "SpotifyExternalUrl.h"

class SpotifyItem : public QObject
{
	Q_OBJECT

	Q_PROPERTY(SpotifyExternalUrl *external_urls READ externalUrls WRITE setExternalUrls)

	public:
		Q_INVOKABLE SpotifyItem();

		SpotifyExternalUrl * externalUrls() const;
		void setExternalUrls(SpotifyExternalUrl* externalUrls);

	private:
		SpotifyExternalUrl *m_externalUrls;
};

class SpotifyTrack : public SpotifyItem
{

};

#endif // SPOTIFYTRACK_H
