#include "Key.h"

namespace as
{
	Key::Key(const char *name)
		: m_name(name)
	{

	}

	KeyValue Key::operator =(const QString &value) const
	{
		return KeyValue(m_name, value);
	}

	KeyValue Key::operator =(const QByteArray &value) const
	{
		return KeyValue(m_name, QString(value));
	}

	KeyValue Key::operator =(int value) const
	{
		return KeyValue(m_name, QString::number(value));
	}
}
