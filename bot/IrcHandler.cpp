#include <IrcCommand>

#include "IrcHandler.h"

IrcHandler::IrcHandler()
{
	setUserName("nplayer");
	setNickName("nplayer");
	setRealName("nplayer");
	setServers(QStringList() << "irc.quakenet.org");

	connect(this, &IrcHandler::connected, this, &IrcHandler::onConnected);
	connect(this, &IrcHandler::noticeMessageReceived, this, &IrcHandler::onNoticeMessageReceived);
	connect(this, &IrcHandler::privateMessageReceived, this, &IrcHandler::onPrivateMessageReceived);
}

void IrcHandler::onConnected()
{
	IrcCommand *command = IrcCommand::createJoin("#swr");

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
