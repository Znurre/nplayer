#ifndef LIST_H
#define LIST_H

#include <QJsonSerializer>

#include "ITemplateComponent.h"

class List : public ITemplateComponent
{
	Q_OBJECT

	Q_PROPERTY(Array<QString> values READ values WRITE setValues NOTIFY valuesChanged)

	Q_PROPERTY(int limit READ limit WRITE setLimit NOTIFY limitChanged)

	public:
		List();

		Array<QString> values() const;
		void setValues(const Array<QString> &values);

		QString render() override;

		int limit() const;
		void setLimit(int limit);

	private:
		Array<QString> m_values;

		int m_limit;

	signals:
		void valuesChanged();
		void limitChanged(int limit);
};

#endif // LIST_H
