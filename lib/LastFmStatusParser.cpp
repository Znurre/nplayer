#include "LastFmStatusParser.h"

LastFMStatusParser::LastFMStatusParser()
	: m_found(false)
{

}

QString LastFMStatusParser::message() const
{
	return m_message;
}

bool LastFMStatusParser::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &attributes)
{
	if (attributes.length() > 0)
	{
		if (attributes.value(0) == "manual-updates")
		{
			m_found = true;
		}
	}

	return QXmlDefaultHandler::startElement(namespaceURI, localName, qName, attributes);
}

bool LastFMStatusParser::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
	if (m_found)
	{
		return false;
	}

	return QXmlDefaultHandler::endElement(namespaceURI, localName, qName);
}

bool LastFMStatusParser::characters(const QString &characters)
{
	if (m_found)
	{
		if (m_message.isEmpty())
		{
			m_message = characters.trimmed();
		}
	}

	return QXmlDefaultHandler::characters(characters);
}
