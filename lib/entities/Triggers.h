#ifndef TRIGGERS_H
#define TRIGGERS_H

#include <QObject>
#include <QJsonSerializer>

class Triggers : public QObject
{
	Q_OBJECT

	Q_PROPERTY(Array<QString> triggers READ triggers WRITE setTriggers NOTIFY triggersChanged)

	public:
		Array<QString> triggers() const;
		void setTriggers(const Array<QString> &triggers);

	private:
		Array<QString> m_triggers;

	signals:
		void triggersChanged();
};

#endif // TRIGGERS_H
