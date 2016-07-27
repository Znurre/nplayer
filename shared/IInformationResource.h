#ifndef IINFORMATIONRESOURCE_H
#define IINFORMATIONRESOURCE_H

#include <QString>

class IInformationResource
{
	public:
		virtual QString id() const = 0;
};

#endif // IINFORMATIONRESOURCE_H
