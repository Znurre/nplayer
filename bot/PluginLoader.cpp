#include <QDebug>

#include "PluginLoader.h"
#include "QMutableListIteratorEx.h"

PluginLoader::PluginLoader(RequestRepository &requestRepository)
	: m_requestRepository(requestRepository)
{

}

void PluginLoader::load(const QString &fileName)
{
	m_plugins << Plugin(fileName, m_requestRepository);
}

void PluginLoader::unload(const QString &fileName)
{
	QMutableListIteratorEx<Plugin> iterator(m_plugins);

	while (iterator)
	{
		const Plugin &plugin = iterator.next();

		if (plugin == fileName)
		{
			iterator.remove();
		}
	}
}
