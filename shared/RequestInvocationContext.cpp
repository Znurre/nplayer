#include "RequestInvocationContext.h"

RequestInvocationContext::RequestInvocationContext(IPluginLoader &pluginLoader)
	: m_pluginLoader(pluginLoader)
{

}

IPluginLoader &RequestInvocationContext::pluginLoader() const
{
	return m_pluginLoader;
}
