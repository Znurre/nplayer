#include <QtGlobal>

#include "RequestInvocationContext.h"

RequestInvocationContext::RequestInvocationContext(IOutputHandler &outputHandler
	, InformationResourceRepository &informationResourceRepository
	, IdGenerator &idGenerator
	, UserMapper &userMapper
	, RequestRepository &requestRepository
	)
	: m_outputHandler(outputHandler)
	, m_informationResourceRepository(informationResourceRepository)
	, m_idGenerator(idGenerator)
	, m_userMapper(userMapper)
	, m_requestRepository(requestRepository)
{

}

IOutputHandler &RequestInvocationContext::outputHandler() const
{
	return m_outputHandler;
}

InformationResourceRepository &RequestInvocationContext::informationResourceRepository() const
{
	return m_informationResourceRepository;
}

IdGenerator &RequestInvocationContext::idGenerator() const
{
	return m_idGenerator;
}

UserMapper &RequestInvocationContext::userMapper() const
{
	return m_userMapper;
}

RequestRepository &RequestInvocationContext::requestRepository() const
{
	return m_requestRepository;
}
