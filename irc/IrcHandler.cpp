#include <IrcCommand>

#include "IrcHandler.h"

IrcHandler::IrcHandler()
	: m_channel("#swr")
	, m_outputHandler(*this, m_channel)
	, m_messageHandler(m_outputHandler, m_requestRepository)
{
	setUserName("MrRoboto");
	setNickName("MrRoboto");
	setRealName("MrRoboto");
	setServers(QStringList() << "irc.quakenet.org");
	setReconnectDelay(10);

	connect(this, &IrcHandler::connected, this, &IrcHandler::onConnected);
	connect(this, &IrcHandler::noticeMessageReceived, this, &IrcHandler::onNoticeMessageReceived);
	connect(this, &IrcHandler::errorMessageReceived, this, &IrcHandler::onErrorMessageReceived);
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
	qDebug() << "NOTICE" << message->content();
}

void IrcHandler::onErrorMessageReceived(IrcErrorMessage *message)
{
	qDebug() << "ERROR" << message->error();
}

void IrcHandler::onPrivateMessageReceived(IrcPrivateMessage *message)
{
	const QString &who = message->nick();
	const QString &content = message->content();

	m_messageHandler.handle(who, content);
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
