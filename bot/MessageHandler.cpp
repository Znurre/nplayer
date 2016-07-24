#include <QDebug>

#include "MessageHandler.h"
#include "RequestInvocationContext.h"
#include "RequestRepository.h"
#include "OutputHandler.h"
#include "RequestProvider.h"

MessageHandler::MessageHandler(OutputHandler &outputHandler, RequestRepository &requestRepository, IPluginLoader &pluginLoader)
	: m_outputHandler(outputHandler)
	, m_requestRepository(requestRepository)
	, m_pluginLoader(pluginLoader)
{
	RequestRegistrator registrator;

	RequestProvider requestProvider;
	requestProvider.definition(registrator);

	registrator.attach(requestRepository);
}

void MessageHandler::handle(IrcPrivateMessage *message)
{
	const QString &who = message->nick();
	const QString &content = message->content();
	const QString &prefix = message->prefix();

	const QStringList &split = content.split(QChar::Space);
	const QStringList &arguments = split.mid(1);

	const QString &trigger = split
		.value(0)
		.toLower();

	IRequest *request = m_requestRepository.resolve(trigger);

	if (request)
	{
		RequestInvocationContext context(m_outputHandler, m_pluginLoader);

		request->invoke(arguments, who, context);
	}

	qDebug() << trigger << arguments;

	Q_UNUSED(who);
	Q_UNUSED(prefix);
}
