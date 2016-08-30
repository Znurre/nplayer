#ifndef USERMAPPER_H
#define USERMAPPER_H

#include <QString>
#include <QHash>
#include <QFile>
#include <QDataStream>

class UserMapper
{
	public:
		UserMapper();

		QString map(const QStringList &arguments, const QString &fallback);
		QString map(const QString &nickname);

		void store(const QString &nickname, const QString &map);

	private:
		QHash<QString, QString> m_mapping;
};

#endif // USERMAPPER_H
