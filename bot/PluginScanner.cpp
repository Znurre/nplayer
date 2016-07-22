#include <QDebug>
#include <QDir>

#include "PluginScanner.h"
#include "PluginLoader.h"

PluginScanner::PluginScanner(PluginLoader &pluginLoader)
	: m_pluginLoader(pluginLoader)
{
	addDirectory("plugins");

	connect(&m_watcher, &QFileSystemWatcher::directoryChanged, this, &PluginScanner::scanDirectory);
}

void PluginScanner::addDirectory(const QString &name)
{
	m_watcher.addPath(name);

	scanDirectory(name);
}

void PluginScanner::scanDirectory(const QString &path)
{
	qDebug() << path;

	const QDir directory(path);
	const QStringList nameFilters = { "*.so" };
	const QFileInfoList &files = directory.entryInfoList(nameFilters);

	for (const QFileInfo &info : files)
	{
//		if (info.lastModified() >= m_timestamp)
//		{
			const QString &filePath = info.filePath();

			m_pluginLoader.unload(filePath);
			m_pluginLoader.load(filePath);
//		}
	}

	m_timestamp = QDateTime::currentDateTime();
}
