#ifndef USERPERIOD_H
#define USERPERIOD_H

#include "IUser.h"
#include "IInformationResource.h"

class User;

class UserPeriod : public IUser
{
	public:
		UserPeriod(User *subject, InformationResourceRepository &repository, IdGenerator &idGenerator);
		~UserPeriod();

		QString id() const override;
		QString key() const override;
		QString url() const override;
		QString user() const override;

		QString period() const override;
		void setPeriod(const QString &period);

	private:
		InformationResourceRepository &m_repository;

		User *m_subject;

		QString m_id;
		QString m_period;
};

#endif // USERPERIOD_H
