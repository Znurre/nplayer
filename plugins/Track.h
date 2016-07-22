#ifndef TRACK_H
#define TRACK_H

#include <QObject>
#include <QJsonSerializer>

class Artist;

class Track : public QObject
{
	Q_OBJECT

	Q_PROPERTY(bool nowPlaying READ nowPlaying WRITE setNowPlaying)

	Q_PROPERTY(QString artist READ artist WRITE setArtist NOTIFY artistChanged)
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

	public:
		Q_INVOKABLE Track();

		bool nowPlaying() const;
		void setNowPlaying(bool nowPlaying);

		QString artist() const;
		void setArtist(const QString &artist);

		QString name() const;
		void setName(const QString &name);

	private:
		bool m_nowPlaying;

		QString m_artist;
		QString m_name;

	signals:
		void artistChanged();
		void nameChanged();
};

Q_DECLARE_METATYPE(Array<Track *>)

#endif // TRACK_H
