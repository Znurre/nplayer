#ifndef WEEKREQUEST_H
#define WEEKREQUEST_H

#include "PeriodRequest.h"

class WeekRequest : public PeriodRequest
{
	public:
		QString trigger() const override;

	protected:
		QString period() const override;
};

#endif // WEEKREQUEST_H
