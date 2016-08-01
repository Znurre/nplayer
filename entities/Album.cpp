#include "Album.h"
#include "InformationResourceRepository.h"
#include "IdGenerator.h"

Album::Album(InformationResourceRepository &repository, IdGenerator &idGenerator)
	: m_id(idGenerator)
{
	repository.add(this);
}

QString Album::id() const
{
	return m_id;
}

QString Album::name() const
{
	return m_name;
}

void Album::setName(const QString &name)
{
	m_name = name;
}

QString Album::artist() const
{
	return m_artist;
}

void Album::setArtist(const QString &artist)
{
	m_artist = artist;
}

Array<QString> Album::tags() const
{
	return m_tags;
}

void Album::setTags(const Array<QString> &tags)
{
	m_tags = tags;
}
