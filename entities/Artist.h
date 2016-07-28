#ifndef ARTIST_H
#define ARTIST_H

#include <QJsonSerializer>

#include "IInformationResource.h"

class InformationResourceRepository;
class IdGenerator;

class Artist : public IInformationResource
{
	Q_OBJECT

	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString bio READ bio WRITE setBio NOTIFY bioChanged)

	Q_PROPERTY(Array<QString> tags READ tags WRITE setTags NOTIFY tagsChanged)

	Q_PROPERTY(int listeners READ listeners WRITE setListeners NOTIFY listenersChanged)

	public:
		Artist(InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator);

		QString id() const override;

		QString name() const;
		void setName(const QString &name);

		QString bio() const;
		void setBio(const QString &bio);

		Array<QString> tags() const;
		void setTags(const Array<QString> &tags);

		int listeners() const;
		void setListeners(int listeners);

	private:
		QString m_id;
		QString m_name;
		QString m_bio;

		Array<QString> m_tags;

		int m_listeners;

	signals:
		void nameChanged();
		void bioChanged();
		void tagsChanged();
		void listenersChanged();
};

#endif // ARTIST_H
