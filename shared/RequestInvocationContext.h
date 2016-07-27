#ifndef REQUESTINVOCATIONCONTEXT_H
#define REQUESTINVOCATIONCONTEXT_H

class IOutputHandler;
class IPluginLoader;
class InformationResourceRepository;
class IdGenerator;

class RequestInvocationContext
{
	public:
		RequestInvocationContext(IOutputHandler &outputHandler, IPluginLoader &pluginLoader, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator);

		IOutputHandler &outputHandler() const;
		IPluginLoader &pluginLoader() const;
		InformationResourceRepository &informationResourceRepository() const;
		IdGenerator &idGenerator() const;

	private:
		IOutputHandler &m_outputHandler;
		IPluginLoader &m_pluginLoader;
		InformationResourceRepository &m_informationResourceRepository;
		IdGenerator &m_idGenerator;
};

#endif // REQUESTINVOCATIONCONTEXT_H
