#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <IrcMessage>

#include "InformationResourceRepository.h"
#include "IdGenerator.h"

class OutputHandler;
class RequestRepository;
class IPluginLoader;

class MessageHandler
{
	public:
		MessageHandler(OutputHandler &outputHandler, RequestRepository &requestRepository, IPluginLoader &pluginLoader);

		void handle(IrcPrivateMessage *message);

	private:
		OutputHandler &m_outputHandler;
		RequestRepository &m_requestRepository;
		IPluginLoader &m_pluginLoader;

		InformationResourceRepository m_informationResourceRepository;
		IdGenerator m_idGenerator;
};

#endif // MESSAGEHANDLER_H
