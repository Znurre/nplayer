#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include "IPluginLoader.h"
#include "IRequestProvider.h"

class PluginLoader : public IPluginLoader
{
	public:
		PluginLoader(RequestRepository &requestRepository);

		void load(const QString &fileName) override;
		void unload(const QString &fileName) override;

	private:
		RequestRepository &m_requestRepository;

		QList<Plugin> m_plugins;
};

#endif // PLUGINLOADER_H
