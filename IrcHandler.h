#ifndef IRCHANDLER_H
#define IRCHANDLER_H

#include <IrcConnection>

#include "OutputHandler.h"
#include "RequestRepository.h"
#include "MessageHandler.h"
#include "Channel.h"

class IrcHandler : public IrcConnection
{
	public:
		IrcHandler();

	private:
		void onConnected();
		void onNoticeMessageReceived(IrcNoticeMessage* message);
		void onErrorMessageReceived(IrcErrorMessage* message);
		void onPrivateMessageReceived(IrcPrivateMessage *message);
		void onJoinMessageReceived(IrcJoinMessage *message);
		void onNamesMessageReceived(IrcNamesMessage *message);
		void onPartMessageReceived(IrcPartMessage *message);

		Channel m_channel;
		OutputHandler m_outputHandler;
		RequestRepository m_requestRepository;
		MessageHandler m_messageHandler;
};

#endif // IRCHANDLER_H
