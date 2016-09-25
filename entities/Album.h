#ifndef ALBUM_H
#define ALBUM_H

#include <QObject>
#include <QJsonSerializer>

#include "IInformationResource.h"
#include "InformationResourceRepository.h"
#include "RequestHandler.h"

#include "entities/Track.h"

class InformationResourceRepository;
class IdGenerator;

class Album : public InformationResource<Album>
{
	Q_OBJECT

	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString artist READ artist WRITE setArtist NOTIFY artistChanged)
	Q_PROPERTY(QString user READ user WRITE setUser NOTIFY userChanged)
	Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)

	Q_PROPERTY(Array<QString> tags READ tags WRITE setTags NOTIFY tagsChanged)
	Q_PROPERTY(Array<Track *> tracks READ tracks WRITE setTracks)

	Q_PROPERTY(int userPlayCount READ userPlayCount WRITE setUserPlayCount NOTIFY userPlayCountChanged)

	public:
		Album(InformationResourceRepository &repository, IdGenerator &idGenerator);
		~Album();

		QString id() const override;
		QString key() const override;

		QString name() const;
		void setName(const QString &name);

		QString artist() const;
		void setArtist(const QString &artist);

		QString user() const;
		void setUser(const QString &user);

		QString url() const override;
		void setUrl(const QString &url);

		Array<QString> tags();
		void setTags(const Array<QString> &tags);

		Array<Track *> tracks() const;
		void setTracks(const Array<Track *> &tracks);

		int userPlayCount();
		void setUserPlayCount(int userPlayCount);

	private:
		void fetchExtendedInfo() override;

		RequestHandler m_requestHandler;
		InformationResourceRepository &m_repository;

		QString m_id;
		QString m_name;
		QString m_artist;
		QString m_user;
		QString m_url;

		Array<QString> m_tags;
		Array<Track *> m_tracks;

		int m_userPlayCount;

	signals:
		void nameChanged();
		void artistChanged();
		void urlChanged();
		void tagsChanged();
		void userChanged();
		void userPlayCountChanged(int userPlayCount);
};

Q_DECLARE_METATYPE(Array<Album *>)

#endif // ALBUM_H
