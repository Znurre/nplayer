#ifndef STATUSRESPONSE_H
#define STATUSRESPONSE_H

#include <QObject>
#include <QString>

class StatusResponse : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

	public:
		QString message() const;
		void setMessage(const QString &message);

	private:
		QString m_message;

	signals:
		void messageChanged();
};

#endif // STATUSRESPONSE_H
