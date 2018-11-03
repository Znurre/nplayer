#include <QVariant>

#include "QStringEx.h"

StringToken::StringToken(const char *value)
{
	m_value = value;
}

StringToken::StringToken(const QString &value)
{
	m_value = value;
}

StringToken::StringToken(const int value)
{
	m_value = QString::number(value);
}

StringToken::StringToken(const QByteArray &value)
{
	m_value = QString::fromUtf8(value);
}

StringToken::StringToken(const QJsonValue &value)
{
	const QVariant &variant = value.toVariant();

	m_value = variant.toString();
}

StringToken::operator QString() const
{
	return m_value;
}
