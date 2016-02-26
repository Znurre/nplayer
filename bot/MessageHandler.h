#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <IrcMessage>

#include "PluginLoader.h"
#include "RequestRepository.h"

class MessageHandler
{
	public:
		MessageHandler();

		void handle(IrcPrivateMessage *message);

	private:
		RequestRepository m_requestRepository;
		PluginLoader m_pluginLoader;
};

#endif // MESSAGEHANDLER_H
