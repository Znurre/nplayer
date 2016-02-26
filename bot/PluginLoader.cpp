#include <QDebug>

#include "PluginLoader.h"

PluginLoader::PluginLoader(RequestRepository &requestRepository)
	: m_requestRepository(requestRepository)
{

}

void PluginLoader::load(const QString &fileName)
{
	qDebug() << "Loading plugin" << fileName;

	Plugin *plugin = new Plugin(fileName);
	plugin->load(m_requestRepository);

	m_plugins << plugin;
}

void PluginLoader::unload(const QString &fileName)
{
	for (Plugin *plugin : m_plugins)
	{
		if (plugin->fileName() == fileName)
		{
			plugin->unload(m_requestRepository);
		}
	}
}
