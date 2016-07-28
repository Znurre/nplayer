#ifndef ITEMPLATECOMPONENT_H
#define ITEMPLATECOMPONENT_H

#include <QObject>
#include <QString>
#include <QQmlListProperty>
#include <QQuickItem>

class ITemplateComponent : public QQuickItem
{
	Q_OBJECT

	const QString SPACE = QString(QChar::Space);

	public:
		virtual QString render()
		{
			return assemble(" | ");
		}

	protected:
		QString assemble()
		{
			return assemble(SPACE);
		}

		QString assemble(const QString &separator)
		{
			QStringList components;

			for (QObject *child: children())
			{
				ITemplateComponent *component = qobject_cast<ITemplateComponent *>(child);

				if (component)
				{
					const QString &content = component->render();

					if (!content.isEmpty())
					{
						components << content;
					}
				}
			}

			return components.join(separator);
		}
};

#endif // ITEMPLATECOMPONENT_H
