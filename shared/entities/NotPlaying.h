#ifndef NOTPLAYING_H
#define NOTPLAYING_H

#include <QObject>

class NotPlaying : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString user READ user WRITE setUser NOTIFY userChanged)

	public:
		NotPlaying();

		QString user() const;
		void setUser(const QString &user);

	private:
		QString m_user;

	signals:
		void userChanged();
};

#endif // NOTPLAYING_H
