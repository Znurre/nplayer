#ifndef TAG_H
#define TAG_H

#include "IInformationResource.h"

class Tag : public InformationResource<Tag>
{
	Q_OBJECT

	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)

	public:
		Tag(InformationResourceRepository &repository, IdGenerator &idGenerator);

		QString id() const override;

		QString name() const;
		void setName(const QString &name);

		QString description() const;
		void setDescription(const QString &description);

	private:
		QString m_id;
		QString m_name;
		QString m_description;

	signals:
		void nameChanged();
		void descriptionChanged();
};

#endif // TAG_H
