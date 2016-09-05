#include "User.h"
#include "IdGenerator.h"
#include "InformationResourceRepository.h"

#include "iterators/UserArtistIterator.h"

User::User(InformationResourceRepository &repository, IdGenerator &idGenerator)
	: m_requestHandler(repository, idGenerator)
	, m_id(idGenerator)
	, m_playCount(0)
{
	repository.add(this);
	
	registerIterator<UserArtistIterator>();
}

QString User::id() const
{
	return m_id;
}

QString User::key() const
{
	return m_user;
}

QString User::user() const
{
	return m_user;
}

void User::setUser(const QString &user)
{
	m_user = user;
}

QString User::country() const
{
	return m_country;
}

void User::setCountry(const QString &country)
{
	m_country = country;
}

QString User::url() const
{
	return m_url;
}

void User::setUrl(const QString &url)
{
	m_url = url;
}

QDateTime User::registered() const
{
	return m_registered;
}

void User::setRegistered(const QDateTime &registered)
{
	m_registered = registered;
}

int User::playCount() const
{
	return m_playCount;
}

void User::setPlayCount(int playCount)
{
	m_playCount = playCount;
}
