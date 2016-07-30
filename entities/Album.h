#ifndef ALBUM_H
#define ALBUM_H

#include <QObject>
#include <QJsonSerializer>

class Album : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

	public:
		Q_INVOKABLE Album();

		QString name() const;
		void setName(const QString &name);

		operator bool() const;

	private:
		QString m_name;

	signals:
		void nameChanged();
};

Q_DECLARE_METATYPE(Array<Album *>)

#endif // ALBUM_H
