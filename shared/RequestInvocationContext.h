#ifndef REQUESTINVOCATIONCONTEXT_H
#define REQUESTINVOCATIONCONTEXT_H

class IOutputHandler;
class IPluginLoader;
class InformationResourceRepository;

class RequestInvocationContext
{
	public:
		RequestInvocationContext(IOutputHandler &outputHandler, IPluginLoader &pluginLoader, InformationResourceRepository &informationResourceRepository);

		IOutputHandler &outputHandler() const;
		IPluginLoader &pluginLoader() const;
		InformationResourceRepository &informationResourceRepository() const;

	private:
		IOutputHandler &m_outputHandler;
		IPluginLoader &m_pluginLoader;
		InformationResourceRepository &m_informationResourceRepository;
};

#endif // REQUESTINVOCATIONCONTEXT_H
