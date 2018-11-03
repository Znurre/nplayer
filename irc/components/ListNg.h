#ifndef LISTNG_H
#define LISTNG_H

#include <QQuickItem>
#include <QJSValue>

#include "ITemplateComponent.h"

class ListNg : public ITemplateComponent
{
	Q_OBJECT

	Q_PROPERTY(QList<QObject *> values READ values WRITE setValues NOTIFY valuesChanged)
	Q_PROPERTY(QQmlComponent *delegate READ delegate WRITE setDelegate NOTIFY delegateChanged)

	Q_PROPERTY(int limit READ limit WRITE setLimit NOTIFY limitChanged)

	public:
		ListNg();

		QList<QObject *> values() const;
		void setValues(const QList<QObject *> &values);

		QQmlComponent *delegate() const;
		void setDelegate(QQmlComponent *delegate);

		int limit() const;
		void setLimit(int limit);

		QString render() override;

	private:
		QList<QObject *> m_values;
		QQmlComponent * m_delegate;

		int m_limit;

	signals:
		void valuesChanged();
		void delegateChanged();
		void limitChanged();
};

#endif // LISTNG_H
