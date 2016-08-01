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

Album::operator bool() const
{
	return !m_name.isEmpty();
}
