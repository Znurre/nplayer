#ifndef REQUESTINVOCATIONCONTEXT_H
#define REQUESTINVOCATIONCONTEXT_H

class IPluginLoader;

class RequestInvocationContext
{
	public:
		RequestInvocationContext(IPluginLoader &pluginLoader);

		IPluginLoader &pluginLoader() const;

	private:
		IPluginLoader &m_pluginLoader;
};

#endif // REQUESTINVOCATIONCONTEXT_H
