#include "Channel.h"

Channel::Channel(const QString &name)
	: m_name(name)
{

}

QStringList Channel::names() const
{
	return m_names;
}

void Channel::setNames(const QStringList &names)
{
	m_names = names;
}

void Channel::addName(const QString &name)
{
	m_names.append(name);
}

void Channel::removeName(const QString &name)
{
	m_names.removeAll(name);
}

Channel::operator QString() const
{
	return m_name;
}
