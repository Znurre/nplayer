#include "User.h"

User::User()
{

}

QString User::username() const
{
	return m_username;
}

void User::setUsername(const QString &username)
{
	m_username = username;
}
