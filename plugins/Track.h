#ifndef TRACK_H
#define TRACK_H

#include <QObject>
#include <QJsonSerializer>

#include "RequestHandler.h"

class Artist;
class Track;

template<class T>
using Callback = T (*)(Track &);

class Track : public QObject
{
	Q_OBJECT

	Q_PROPERTY(bool nowPlaying READ nowPlaying WRITE setNowPlaying)

	Q_PROPERTY(QString artist READ artist WRITE setArtist NOTIFY artistChanged)
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString album READ album WRITE setAlbum NOTIFY albumChanged)

	Q_PROPERTY(Array<QString> tags READ tags WRITE setTags NOTIFY tagsChanged)

	Q_PROPERTY(int userPlayCount READ userPlayCount WRITE setUserPlayCount NOTIFY userPlayCountChanged)

	public:
		Q_INVOKABLE Track();

		bool nowPlaying() const;
		void setNowPlaying(bool nowPlaying);

		QString artist() const;
		void setArtist(const QString &artist);

		QString name() const;
		void setName(const QString &name);

		QString album() const;
		void setAlbum(const QString &album);

		Array<QString> tags();
		void setTags(const Array<QString> &tags);

		int userPlayCount();
		void setUserPlayCount(int userPlayCount);

	private:
		template<class T>
		T property(Callback<T> callback)
		{
			if (!m_fetched)
			{
				m_fetched = true;
				m_requestHandler
					.get(this, "track.getInfo"
						, as::artist = m_artist
						, as::track = m_name
						, as::user = "Znurre"
					);
			}

			return callback(*this);
		}

		RequestHandler m_requestHandler;

		bool m_nowPlaying;
		bool m_fetched;

		QString m_artist;
		QString m_name;
		QString m_album;

		Array<QString> m_tags;

		int m_userPlayCount;

	signals:
		void artistChanged();
		void nameChanged();
		void albumChanged();
		void tagsChanged();
		void userPlayCountChanged();
};

Q_DECLARE_METATYPE(Array<Track *>)

#endif // TRACK_H
