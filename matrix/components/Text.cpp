#include "Text.h"
#include "StringUtils.h"

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
	return 0;
}

void Text::setMaxLength(int maxLength)
{
	Q_UNUSED(maxLength);
}

QString Text::render()
{
	return StringUtils::elide(m_text, 2048);
}
