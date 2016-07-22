#ifndef REQUESTINVOCATIONCONTEXT_H
#define REQUESTINVOCATIONCONTEXT_H

class IOutputHandler;
class IPluginLoader;

class RequestInvocationContext
{
	public:
		RequestInvocationContext(IOutputHandler &outputHandler);

		IOutputHandler &outputHandler() const;

	private:
		IOutputHandler &m_outputHandler;
};

#endif // REQUESTINVOCATIONCONTEXT_H
