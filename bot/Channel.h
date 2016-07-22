#ifndef CHANNEL_H
#define CHANNEL_H

#include <QString>
#include <QStringList>

class Channel
{
	public:
		Channel(const QString &name);

		QStringList names() const;

		void setNames(const QStringList &names);
		void addName(const QString &name);
		void removeName(const QString &name);

		operator QString() const;

	private:
		QString m_name;
		QStringList m_names;
};

#endif // CHANNEL_H
