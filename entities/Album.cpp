#include "Album.h"

Album::Album()
{

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
