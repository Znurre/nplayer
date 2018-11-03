#include <QDebug>
#include <QQmlContext>
#include <QQmlEngine>

#include "MessageHandler.h"
#include "RequestInvocationContext.h"
#include "RequestRepository.h"
#include "IOutputHandler.h"
#include "TriggerWalker.h"

#include "components/ITemplateComponent.h"

MessageHandler::MessageHandler(IOutputHandler &outputHandler, RequestRepository &requestRepository)
	: m_outputHandler(outputHandler)
	, m_requestRepository(requestRepository)
{

}

void MessageHandler::handle(const QString &who, const QString &content)
{
	const QStringList &split = content.split(QChar::Space);
	const QStringList &arguments = split.mid(1);

	const QString &trigger = split
		.value(0)
		.toLower();

	const RequestInvocationContext context(m_outputHandler, m_informationResourceRepository, m_idGenerator, m_userMapper, m_requestRepository);
	const TriggerWalker walker(m_requestRepository, context);
	const RequestResponse &response = walker.walk(trigger, who, arguments);

	if (response.isValid())
	{
		const QString &templateName = response.templateName();

		if (!templateName.isEmpty())
		{
			QQmlEngine engine;
			QQmlComponent component(&engine, templateName);

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
}
