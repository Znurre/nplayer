#ifndef USER_H
#define USER_H

#include <QDateTime>

#include "IInformationResource.h"
#include "InformationResourceRepository.h"
#include "RequestHandler.h"

class User : public InformationResource<User>
{
	Q_OBJECT

	Q_PROPERTY(QString user READ user WRITE setUser NOTIFY userChanged)
	Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged)
	Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)

	Q_PROPERTY(QDateTime registered READ registered WRITE setRegistered NOTIFY registeredChanged)

	Q_PROPERTY(int playCount READ playCount WRITE setPlayCount NOTIFY playCountChanged)

	public:
		User(InformationResourceRepository &repository, IdGenerator &idGenerator);
		~User();

		QString id() const override;
		QString key() const override;

		QString user() const;
		void setUser(const QString &user);

		QString country() const;
		void setCountry(const QString &country);

		QString url() const override;
		void setUrl(const QString &url);

		QDateTime registered() const;
		void setRegistered(const QDateTime &registered);

		int playCount() const;
		void setPlayCount(int playCount);

	private:
		RequestHandler m_requestHandler;
		InformationResourceRepository &m_repository;

		QString m_user;
		QString m_country;
		QString m_url;
		QString m_id;

		QDateTime m_registered;

		int m_playCount;

	signals:
		void userChanged();
		void countryChanged();
		void urlChanged();
		void registeredChanged();
		void playCountChanged();
};

#endif // USER_H
