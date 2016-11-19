#include "IteratorKey.h"

IteratorKey::IteratorKey(const QString &key)
	: m_key(key)
{

}

bool IteratorKey::operator ==(const IteratorKey &other) const
{
	return other.m_key == m_key;
}

uint qHash(const IteratorKey &key)
{
	return qHash(key.m_key);
}
