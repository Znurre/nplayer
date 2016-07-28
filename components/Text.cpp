#include "Text.h"
#include "StringUtils.h"

Text::Text()
	: m_maxLength(0)
{

}

QString Text::text() const
{
	return m_text;
}

void Text::setText(const QString &text)
{
	m_text = text;
}

int Text::maxLength() const
{
	return m_maxLength;
}

void Text::setMaxLength(int maxLength)
{
	m_maxLength = maxLength;
}

QString Text::render()
{
	if (m_maxLength > 0)
	{
		return StringUtils::elide(m_text, m_maxLength);
	}

	return m_text;
}
