#ifndef UTILITY_H
#define UTILITY_H

#include <QObject>
#include <QJsonSerializer>
#include <QQmlEngine>

class Utility : public QObject
{
	Q_OBJECT

	public:
		static QObject *instance(QQmlEngine *engine, QJSEngine *scriptEngine);

		Q_INVOKABLE bool isNotEmpty(const Array<QString> &array);
};
#endif // UTILITY_H
