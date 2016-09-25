#include "UserPeriod.h"
#include "IdGenerator.h"
#include "User.h"

#include "iterators/UserArtistIterator.h"
#include "iterators/UserTrackIterator.h"
#include "iterators/UserTagIterator.h"

UserPeriod::UserPeriod(User *subject, InformationResourceRepository &repository, IdGenerator &idGenerator)
	: m_repository(repository)
	, m_subject(subject)
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
	return m_subject->key() + m_period;
}

QString UserPeriod::url() const
{
	return QString();
}

QString UserPeriod::user() const
{
	return m_subject->user();
}

QString UserPeriod::period() const
{
	return m_period;
}

void UserPeriod::setPeriod(const QString &period)
{
	m_period = period;
}
