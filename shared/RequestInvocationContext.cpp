#include <QtGlobal>

#include "RequestInvocationContext.h"

RequestInvocationContext::RequestInvocationContext(IOutputHandler &outputHandler, IPluginLoader &pluginLoader, InformationResourceRepository &informationResourceRepository)
	: m_outputHandler(outputHandler)
	, m_pluginLoader(pluginLoader)
	, m_informationResourceRepository(informationResourceRepository)
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
