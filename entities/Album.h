#ifndef ALBUM_H
#define ALBUM_H

#include <QObject>
#include <QJsonSerializer>

#include "IInformationResource.h"

class InformationResourceRepository;
class IdGenerator;

class Album : public InformationResource<Album>
{
	Q_OBJECT

	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

	public:
		Album(InformationResourceRepository &repository, IdGenerator &idGenerator);

		QString id() const override;

		QString name() const;
		void setName(const QString &name);

		operator bool() const;

	private:
		QString m_id;
		QString m_name;

	signals:
		void nameChanged();
};

Q_DECLARE_METATYPE(Array<Album *>)

#endif // ALBUM_H
