#ifndef ARTIST_H
#define ARTIST_H

#include <QObject>

class Artist : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString text READ text WRITE setText)

	public:
		Q_INVOKABLE Artist();

		QString text() const;
		void setText(const QString &text);

	private:
		QString m_text;
};

#endif // ARTIST_H
