#ifndef MONTHREQUEST_H
#define MONTHREQUEST_H

#include "PeriodRequest.h"

class MonthRequest : public PeriodRequest
{
	public:
		QString trigger() const override;

	protected:
		QString period() const override;
};

#endif // MONTHREQUEST_H
