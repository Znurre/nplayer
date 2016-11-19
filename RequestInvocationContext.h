#ifndef REQUESTINVOCATIONCONTEXT_H
#define REQUESTINVOCATIONCONTEXT_H

class IOutputHandler;
class IPluginLoader;
class InformationResourceRepository;
class IdGenerator;
class UserMapper;
class RequestRepository;

class RequestInvocationContext
{
	public:
		RequestInvocationContext(IOutputHandler &outputHandler
			, InformationResourceRepository &informationResourceRepository
			, IdGenerator &idGenerator
			, UserMapper &userMapper
			, RequestRepository &requestRepository
			);

		IOutputHandler &outputHandler() const;
		InformationResourceRepository &informationResourceRepository() const;
		IdGenerator &idGenerator() const;
		UserMapper &userMapper() const;
		RequestRepository &requestRepository() const;

	private:
		IOutputHandler &m_outputHandler;
		InformationResourceRepository &m_informationResourceRepository;
		IdGenerator &m_idGenerator;
		UserMapper &m_userMapper;
		RequestRepository &m_requestRepository;
};

#endif // REQUESTINVOCATIONCONTEXT_H
