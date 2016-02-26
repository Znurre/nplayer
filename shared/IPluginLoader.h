#ifndef IPLUGINLOADER_H
#define IPLUGINLOADER_H

#include <QString>

class IPluginLoader
{
	public:
		virtual void load(const QString &fileName) = 0;
		virtual void unload(const QString &fileName) = 0;
};

#endif // IPLUGINLOADER_H
