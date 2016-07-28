#ifndef IINFORMATIONRESOURCE_H
#define IINFORMATIONRESOURCE_H

#include <QObject>
#include <QString>

class IInformationResource : public QObject
{
	Q_OBJECT

	public:
		virtual QString id() const = 0;
};

#endif // IINFORMATIONRESOURCE_H
