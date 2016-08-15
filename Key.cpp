#include "Key.h"

namespace as
{
	Key::Key(const char *name)
		: m_name(name)
	{

	}

	KeyValue Key::operator =(const QString &value) const
	{
		return KeyValue(m_name, value, false);
	}

	KeyValue Key::operator =(const QByteArray &value) const
	{
		return KeyValue(m_name, QString(value), false);
	}

	KeyValue Key::operator =(int value) const
	{
		return KeyValue(m_name, QString::number(value), false);
	}

	RequiredKey::RequiredKey(const Key &key)
		: m_name(key.m_name)
	{

	}

	KeyValue RequiredKey::operator =(const QString &value) const
	{
		return KeyValue(m_name, value, true);
	}

	RequiredKey required(const Key &key)
	{
		return RequiredKey(key);
	}
}
