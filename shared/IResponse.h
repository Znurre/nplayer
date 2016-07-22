#ifndef IRESPONSE_H
#define IRESPONSE_H

#include <QString>

class IResponse
{
	public:
		virtual QString id() = 0;
};

#endif // IRESPONSE_H
