#include "UserPeriod.h"
#include "IdGenerator.h"
#include "User.h"

#include "iterators/UserArtistIterator.h"
#include "iterators/UserTrackIterator.h"
#include "iterators/UserTagIterator.h"

UserPeriod::UserPeriod(InformationResourceRepository &repository, IdGenerator &idGenerator)
	: m_repository(repository)
	, m_id(idGenerator)
{
	m_repository.add(this);

	registerIterator<UserArtistIterator>();
	registerIterator<UserTrackIterator>();
}

UserPeriod::~UserPeriod()
{
	m_repository.remove(this);
}

QString UserPeriod::id() const
{
	return m_id;
}

QString UserPeriod::key() const
{
	return m_user + m_period;
}

QString UserPeriod::url() const
{
	return QString();
}

QString UserPeriod::user() const
{
	return m_user;
}

void UserPeriod::setUser(const QString &user)
{
	m_user = user;
}

QString UserPeriod::period() const
{
	return m_period;
}

void UserPeriod::setPeriod(const QString &period)
{
	m_period = period;
}
