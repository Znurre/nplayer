#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "InformationResourceRepository.h"
#include "IdGenerator.h"
#include "UserMapper.h"

class IOutputHandler;
class RequestRepository;
class IPluginLoader;

class MessageHandler
{
	public:
		MessageHandler(IOutputHandler &outputHandler, RequestRepository &requestRepository);

		void handle(const QString &who, const QString &content);

	private:
		IOutputHandler &m_outputHandler;
		RequestRepository &m_requestRepository;

		InformationResourceRepository m_informationResourceRepository;
		IdGenerator m_idGenerator;
		UserMapper m_userMapper;
};

#endif // MESSAGEHANDLER_H
