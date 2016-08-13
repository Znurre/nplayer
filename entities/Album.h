#ifndef ALBUM_H
#define ALBUM_H

#include <QObject>
#include <QJsonSerializer>

#include "IInformationResource.h"
#include "RequestHandler.h"

#include "entities/Track.h"

class InformationResourceRepository;
class IdGenerator;

class Album : public InformationResource<Album>
{
	Q_OBJECT

	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString artist READ artist WRITE setArtist NOTIFY artistChanged)

	Q_PROPERTY(Array<QString> tags READ tags WRITE setTags NOTIFY tagsChanged)
	Q_PROPERTY(Array<Track *> tracks READ tracks WRITE setTracks)

	public:
		Album(InformationResourceRepository &repository, IdGenerator &idGenerator);

		QString id() const override;

		QString name() const;
		void setName(const QString &name);

		QString artist() const;
		void setArtist(const QString &artist);

		Array<QString> tags();
		void setTags(const Array<QString> &tags);

		Array<Track *> tracks() const;
		void setTracks(const Array<Track *> &tracks);

	private:
		void fetchExtendedInfo() override;

		RequestHandler m_requestHandler;

		QString m_id;
		QString m_name;
		QString m_artist;

		Array<QString> m_tags;

		Array<Track *> m_tracks;

	signals:
		void nameChanged();
		void artistChanged();
		void tagsChanged();
};

Q_DECLARE_METATYPE(Array<Album *>)

#endif // ALBUM_H
