#ifndef REQUESTINVOCATIONCONTEXT_H
#define REQUESTINVOCATIONCONTEXT_H

class IOutputHandler;
class IPluginLoader;

class RequestInvocationContext
{
	public:
		RequestInvocationContext(IOutputHandler &outputHandler, IPluginLoader &pluginLoader);

		IOutputHandler &outputHandler() const;
		IPluginLoader &pluginLoader() const;

	private:
		IOutputHandler &m_outputHandler;
		IPluginLoader &m_pluginLoader;
};

#endif // REQUESTINVOCATIONCONTEXT_H
