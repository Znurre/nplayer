#include "Text.h"

Text::Text()
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

QString Text::render()
{
	return m_text;
}
