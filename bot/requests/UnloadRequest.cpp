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

void UnloadRequest::invoke(const QStringList &arguments, const RequestInvocationContext &context)
{
	const QString &fileName = arguments.join(QChar::Space);

	IPluginLoader &pluginLoader = context.pluginLoader();
	pluginLoader.unload(fileName);
}
