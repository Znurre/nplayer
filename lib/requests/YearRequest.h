#ifndef YEARREQUEST_H
#define YEARREQUEST_H

#include "PeriodRequest.h"

class YearRequest : public PeriodRequest
{
	public:
		QString trigger() const override;

	protected:
		QString period() const override;
};

#endif // YEARREQUEST_H
