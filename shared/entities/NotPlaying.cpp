#include "NotPlaying.h"

NotPlaying::NotPlaying()
{

}

QString NotPlaying::user() const
{
	return m_user;
}

void NotPlaying::setUser(const QString &user)
{
	m_user = user;
}
