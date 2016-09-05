#ifndef TAG_H
#define TAG_H

#include "IInformationResource.h"
#include "InformationResourceRepository.h"

class Tag : public InformationResource<Tag>
{
	Q_OBJECT

	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
	Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)

	public:
		Tag(InformationResourceRepository &repository, IdGenerator &idGenerator);
		~Tag();

		QString id() const override;
		QString key() const override;

		QString name() const;
		void setName(const QString &name);

		QString description() const;
		void setDescription(const QString &description);

		QString url() const override;
		void setUrl(const QString &url);

	private:
		InformationResourceRepository &m_repository;

		QString m_id;
		QString m_name;
		QString m_description;
		QString m_url;

	signals:
		void nameChanged();
		void descriptionChanged();
		void urlChanged();
};

#endif // TAG_H
