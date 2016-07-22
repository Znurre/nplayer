#ifndef PLUGINSCANNER_H
#define PLUGINSCANNER_H

#include <QFileSystemWatcher>
#include <QDateTime>

class PluginLoader;

class PluginScanner : public QObject
{
	public:
		PluginScanner(PluginLoader &pluginLoader);

	private:
		void addDirectory(const QString &name);
		void scanDirectory(const QString &path);

		PluginLoader &m_pluginLoader;

		QFileSystemWatcher m_watcher;
		QDateTime m_timestamp;
};

#endif // PLUGINSCANNER_H
