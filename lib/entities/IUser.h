#ifndef IUSER_H
#define IUSER_H

#include <QString>

#include "IInformationResource.h"

class IUser : public InformationResource<IUser>
{
	public:
		virtual QString user() const = 0;
		virtual QString period() const = 0;
};

#endif // IUSER_H
