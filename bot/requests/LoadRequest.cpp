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

void LoadRequest::invoke(const QStringList &arguments, const RequestInvocationContext &context)
{
	const QString &fileName = arguments.join(QChar::Space);

	IPluginLoader &pluginLoader = context.pluginLoader();
	pluginLoader.load(fileName);
}
