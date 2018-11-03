#include "Conditional.h"

Conditional::Conditional()
	: m_condition(false)
{

}

bool Conditional::condition() const
{
	return m_condition;
}

void Conditional::setCondition(bool condition)
{
	m_condition = condition;
}

QString Conditional::render()
{
	if (m_condition)
	{
		return ITemplateComponent::assemble();
	}

	return QString();
}
