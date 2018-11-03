#ifndef LASTFMSTATUSPARSER_H
#define LASTFMSTATUSPARSER_H

#include <QXmlDefaultHandler>

class LastFMStatusParser : public QXmlDefaultHandler
{
	public:
		LastFMStatusParser();

		QString message() const;

		bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &attributes);
		bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
		bool characters(const QString &characters) override;

	private:
		bool m_found;

		QString m_message;
};

#endif // LASTFMSTATUSPARSER_H
