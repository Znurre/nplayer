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

void LoadRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(arguments);
	Q_UNUSED(who);
	Q_UNUSED(context);
}
