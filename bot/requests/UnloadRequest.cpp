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

void UnloadRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(arguments);
	Q_UNUSED(who);
	Q_UNUSED(context);
}
