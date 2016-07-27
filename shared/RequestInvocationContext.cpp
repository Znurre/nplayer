#include <QtGlobal>

#include "RequestInvocationContext.h"

RequestInvocationContext::RequestInvocationContext(IOutputHandler &outputHandler, IPluginLoader &pluginLoader, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator)
	: m_outputHandler(outputHandler)
	, m_pluginLoader(pluginLoader)
	, m_informationResourceRepository(informationResourceRepository)
	, m_idGenerator(idGenerator)
{

}

IOutputHandler &RequestInvocationContext::outputHandler() const
{
	return m_outputHandler;
}

IPluginLoader &RequestInvocationContext::pluginLoader() const
{
	return m_pluginLoader;
}

InformationResourceRepository &RequestInvocationContext::informationResourceRepository() const
{
	return m_informationResourceRepository;
}

IdGenerator &RequestInvocationContext::idGenerator() const
{
	return m_idGenerator;
}
