#include <QQmlContext>
#include <QQmlEngine>
#include <QJsonSerializer>

#include "ListNg.h"

ListNg::ListNg()
	: m_limit(0)
{

}

QList<QObject *> ListNg::values() const
{
	return m_values;
}

void ListNg::setValues(const QList<QObject *> &values)
{
	m_values = values;
}

QQmlComponent *ListNg::delegate() const
{
	return m_delegate;
}

void ListNg::setDelegate(QQmlComponent *delegate)
{
	m_delegate = delegate;
}

int ListNg::limit() const
{
	return m_limit;
}

void ListNg::setLimit(int limit)
{
	m_limit = limit;
}

QString ListNg::render()
{
	if (m_delegate)
	{
		QQmlEngine *engine = qmlEngine(this);
		QQmlContext context(engine);

		QStringList result;

		for (int i = 0
			; i < m_values.count() && (!m_limit || i < m_limit)
			; i++)
		{
			QObject *object = m_values[i];

			context.setContextObject(object);

			ITemplateComponent *component = (ITemplateComponent *)m_delegate->create(&context);

			if (!component)
			{
				qDebug() << m_delegate->errorString();
			}
			else
			{
				result << component->render();
			}

			delete component;
		}

		return result.join(", ");
	}

	return QString();
}
