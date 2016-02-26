#ifndef IRCHANDLER_H
#define IRCHANDLER_H

#include <IrcConnection>

#include "MessageHandler.h"

class IrcHandler : public IrcConnection
{
	public:
		IrcHandler();

	private:
		void onConnected();
		void onNoticeMessageReceived(IrcNoticeMessage* message);
		void onPrivateMessageReceived(IrcPrivateMessage *message);

		MessageHandler m_messageHandler;
};

#endif // IRCHANDLER_H
