#include <QDebug>

#include "MessageHandler.h"
#include "RequestProvider.h"
#include "RequestInvocationContext.h"

MessageHandler::MessageHandler()
	: m_pluginLoader(m_requestRepository)
{
	RequestRegistrator requestRegistrator;
	RequestProvider requestProvider;
	requestProvider.definition(requestRegistrator);

	requestRegistrator.attach(m_requestRepository);
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
		RequestInvocationContext context(m_pluginLoader);

		request->invoke(arguments, context);
	}

	qDebug() << trigger << arguments;

	Q_UNUSED(who);
	Q_UNUSED(prefix);
}
