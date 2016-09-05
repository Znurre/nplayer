#ifndef ARTIST_H
#define ARTIST_H

#include <QJsonSerializer>

#include "IInformationResource.h"
#include "RequestHandler.h"

class InformationResourceRepository;
class IdGenerator;
class ArtistTrackIterator;

class Artist : public InformationResource<Artist>
{
	Q_OBJECT

	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString bio READ bio WRITE setBio NOTIFY bioChanged)
	Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)

	Q_PROPERTY(Array<QString> tags READ tags WRITE setTags NOTIFY tagsChanged)

	Q_PROPERTY(int listeners READ listeners WRITE setListeners NOTIFY listenersChanged)
	Q_PROPERTY(int userPlayCount READ userPlayCount WRITE setUserPlayCount NOTIFY userPlayCountChanged)

	public:
		Artist(InformationResourceRepository &repository, IdGenerator &idGenerator);

		QString id() const override;
		QString key() const override;

		QString name() const;
		void setName(const QString &name);

		QString bio();
		void setBio(const QString &bio);

		QString url() const override;
		void setUrl(const QString &url);

		Array<QString> tags();
		void setTags(const Array<QString> &tags);

		int listeners();
		void setListeners(int listeners);

		int userPlayCount() const;
		void setUserPlayCount(int userPlayCount);

	private:
		void fetchExtendedInfo() override;

		RequestHandler m_requestHandler;

		QString m_id;
		QString m_name;
		QString m_bio;
		QString m_url;

		Array<QString> m_tags;

		int m_listeners;
		int m_userPlayCount;

	signals:
		void nameChanged();
		void bioChanged();
		void urlChanged();
		void tagsChanged();
		void listenersChanged();
		void userPlayCountChanged();
};

Q_DECLARE_METATYPE(Array<Artist *>)

#endif // ARTIST_H
