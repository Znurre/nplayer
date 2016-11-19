#include "Triggers.h"

Array<QString> Triggers::triggers() const
{
	return m_triggers;
}

void Triggers::setTriggers(const Array<QString> &triggers)
{
	m_triggers = triggers;
}
