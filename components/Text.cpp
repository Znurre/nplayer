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

void Text::setText(QString text)
{
	m_text = text.replace(QChar::LineFeed, QChar::Space);
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
