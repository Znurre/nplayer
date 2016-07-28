#include <QStringList>

#include "UnloadRequest.h"
#include "RequestInvocationContext.h"
#include "PluginLoader.h"

UnloadRequest::UnloadRequest()
{

}

QString UnloadRequest::trigger() const
{
	return "!unload";
}

RequestResponse UnloadRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(who);

	const QString &fileName = arguments.join(QChar::Space);

	IPluginLoader &pluginLoader = context.pluginLoader();
	pluginLoader.unload(fileName);

	return RequestResponse();
}
