#include <QtGlobal>

#include "RequestInvocationContext.h"

RequestInvocationContext::RequestInvocationContext(IOutputHandler &outputHandler, IPluginLoader &pluginLoader)
	: m_outputHandler(outputHandler)
	, m_pluginLoader(pluginLoader)
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
