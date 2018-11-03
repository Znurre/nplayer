#include "NotFound.h"

QString NotFound::typeName() const
{
	return m_typeName;
}

void NotFound::setTypeName(const QString &typeName)
{
	m_typeName = typeName;
}
