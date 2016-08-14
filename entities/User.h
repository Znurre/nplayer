#ifndef USER_H
#define USER_H

#include "IInformationResource.h"

class User : public InformationResource<User>
{
	Q_OBJECT

	Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)

	public:
		User();

		QString username() const;
		void setUsername(const QString &username);

	private:
		QString m_username;

	signals:
		void usernameChanged();
};

#endif // USER_H
