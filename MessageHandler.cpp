#include <QDebug>
#include <QQmlContext>
#include <QQmlEngine>

#include "MessageHandler.h"
#include "RequestInvocationContext.h"
#include "RequestRepository.h"
#include "OutputHandler.h"

#include "components/ITemplateComponent.h"

MessageHandler::MessageHandler(OutputHandler &outputHandler, RequestRepository &requestRepository)
	: m_outputHandler(outputHandler)
	, m_requestRepository(requestRepository)
{

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
		const RequestInvocationContext context(m_outputHandler, m_informationResourceRepository, m_idGenerator);
		const RequestResponse &response = request->invoke(arguments, who, context);

		if (response.isValid())
		{
			QQmlEngine engine;
			QQmlComponent component(&engine, response.templateName());

			QQmlContext *context = engine.rootContext();
			context->setContextObject(response.dataContext());

			ITemplateComponent *templateComponent = (ITemplateComponent *)component.create();

			if (!templateComponent)
			{
				qDebug() << component.errorString();

				return;
			}

			const QString &text = templateComponent->render();

			m_outputHandler.say(text);
		}
	}

	qDebug() << trigger << arguments;

	Q_UNUSED(prefix);
}
