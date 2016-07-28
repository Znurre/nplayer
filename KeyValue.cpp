#include "KeyValue.h"
#include "QStringEx.h"

namespace as
{
	KeyValue::KeyValue(const QString &name, const QString &value)
		: m_name(name)
		, m_value(value)
	{

	}

	QString KeyValue::asQueryParameter() const
	{
		const QByteArray &encoded = m_value
			.toUtf8()
			.toPercentEncoding();

		return QStringEx::format("%1=%2", m_name, encoded);
	}

	QString KeyValue::asJoined() const
	{
		return m_name + m_value;
	}

	bool KeyValue::operator <(const KeyValue &other) const
	{
		return m_name < other.m_name;
	}
}
