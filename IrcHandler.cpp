#include <IrcCommand>

#include "IrcHandler.h"

IrcHandler::IrcHandler()
	: m_channel("#swr")
	, m_outputHandler(*this, m_channel)
	, m_messageHandler(m_outputHandler, m_requestRepository)
{
	setUserName("MrRobot");
	setNickName("MrRobot");
	setRealName("MrRobot");
	setServers(QStringList() << "irc.quakenet.org");

	connect(this, &IrcHandler::connected, this, &IrcHandler::onConnected);
	connect(this, &IrcHandler::noticeMessageReceived, this, &IrcHandler::onNoticeMessageReceived);
	connect(this, &IrcHandler::privateMessageReceived, this, &IrcHandler::onPrivateMessageReceived);
	connect(this, &IrcHandler::joinMessageReceived, this, &IrcHandler::onJoinMessageReceived);
	connect(this, &IrcHandler::partMessageReceived, this, &IrcHandler::onPartMessageReceived);
}

void IrcHandler::onConnected()
{
	IrcCommand *command = IrcCommand::createJoin(m_channel);

	sendCommand(command);
}

void IrcHandler::onNoticeMessageReceived(IrcNoticeMessage *message)
{
	qDebug() << message->content();
}

void IrcHandler::onPrivateMessageReceived(IrcPrivateMessage *message)
{
	m_messageHandler.handle(message);
}

void IrcHandler::onJoinMessageReceived(IrcJoinMessage *message)
{
	if (message->flags() & IrcMessage::Own)
	{
		IrcCommand *names = IrcCommand::createNames(m_channel);

		sendCommand(names);
	}
	else
	{
		const QString &name = message->nick();

		m_channel.addName(name);
	}
}

void IrcHandler::onNamesMessageReceived(IrcNamesMessage *message)
{
	const QStringList &names = message->names();

	m_channel.setNames(names);
}

void IrcHandler::onPartMessageReceived(IrcPartMessage *message)
{
	const QString &name = message->nick();

	m_channel.removeName(name);
}
