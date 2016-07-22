#include <IrcCommand>

#include "OutputHandler.h"
#include "IrcHandler.h"

OutputHandler::OutputHandler(IrcHandler &ircHandler, Channel &channel)
	: m_ircHandler(ircHandler)
	, m_channel(channel)
{

}

void OutputHandler::say(const QString &message) const
{
	IrcCommand *command = IrcCommand::createMessage(m_channel, message);

	m_ircHandler.sendCommand(command);
}

void OutputHandler::act(const QString &action) const
{
	IrcCommand *command = IrcCommand::createCtcpAction(m_channel, action);

	m_ircHandler.sendCommand(command);
}

void OutputHandler::notice(const QString &target, const QString &notice) const
{
	Q_UNUSED(target);
	Q_UNUSED(notice);
}

void OutputHandler::message(const QString &target, const QString &message) const
{
	Q_UNUSED(target);
	Q_UNUSED(message);
}
