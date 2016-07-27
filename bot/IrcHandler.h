#ifndef IRCHANDLER_H
#define IRCHANDLER_H

#include <IrcConnection>

#include "OutputHandler.h"
#include "PluginLoader.h"
#include "RequestRepository.h"
#include "PluginScanner.h"
#include "MessageHandler.h"
#include "Channel.h"
#include "InformationResourceRepository.h"

class IrcHandler : public IrcConnection
{
	public:
		IrcHandler();

	private:
		void onConnected();
		void onNoticeMessageReceived(IrcNoticeMessage* message);
		void onPrivateMessageReceived(IrcPrivateMessage *message);
		void onJoinMessageReceived(IrcJoinMessage *message);
		void onNamesMessageReceived(IrcNamesMessage *message);
		void onPartMessageReceived(IrcPartMessage *message);

		Channel m_channel;
		OutputHandler m_outputHandler;
		RequestRepository m_requestRepository;
		PluginLoader m_pluginLoader;
		PluginScanner m_pluginScanner;
		InformationResourceRepository m_informationResourceRepository;
		MessageHandler m_messageHandler;
};

#endif // IRCHANDLER_H
