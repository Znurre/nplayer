#include "KeyValue.h"
#include "QStringEx.h"

namespace as
{
	KeyValue::KeyValue(const QString &name, const QString &value, bool required)
		: m_name(name)
		, m_value(value)
		, m_required(required)
	{

	}

	QString KeyValue::asQueryParameter(bool &isValid) const
	{
		if (m_required)
		{
			isValid &= !m_value.isEmpty();
		}

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
