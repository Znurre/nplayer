#ifndef SPOTIFYEXTERNALURL_H
#define SPOTIFYEXTERNALURL_H

#include <QObject>

class SpotifyExternalUrl : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString spotify READ spotify WRITE setSpotify)

	public:
		Q_INVOKABLE SpotifyExternalUrl() = default;

		QString spotify() const;
		void setSpotify(const QString &spotify);

	private:
		QString m_spotify;
};

Q_DECLARE_METATYPE(SpotifyExternalUrl *)

#endif // SPOTIFYEXTERNALURL_H
