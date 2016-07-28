#include <QStringList>

#include "LoadRequest.h"
#include "RequestInvocationContext.h"
#include "PluginLoader.h"

LoadRequest::LoadRequest()
{

}

QString LoadRequest::trigger() const
{
	return "!load";
}

RequestResponse LoadRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(who);

	const QString &fileName = arguments.join(QChar::Space);

	IPluginLoader &pluginLoader = context.pluginLoader();
	pluginLoader.load(fileName);

	return RequestResponse();
}
