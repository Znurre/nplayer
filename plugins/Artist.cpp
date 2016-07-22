#include "Artist.h"

Artist::Artist()
{

}

QString Artist::text() const
{
	return m_text;
}

void Artist::setText(const QString &text)
{
	m_text = text;
}
