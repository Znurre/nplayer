#include "List.h"

List::List()
{

}

Array<QString> List::values() const
{
	return m_values;
}

void List::setValues(const Array<QString> &values)
{
	m_values = values;
}

QString List::render()
{
	QStringList result;

	for (int i = 0
		; i < m_values.count() && (!m_limit || i < m_limit)
		; i++)
	{
		result << m_values[i];
	}

	return result.join(", ");
}

int List::limit() const
{
	return m_limit;
}

void List::setLimit(int limit)
{
	m_limit = limit;
}
