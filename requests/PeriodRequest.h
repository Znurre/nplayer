#ifndef PERIODREQUEST_H
#define PERIODREQUEST_H

#include "IRequest.h"

class PeriodRequest : public IRequest
{
	public:
		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;

	protected:
		virtual QString period() const = 0;
};

#endif // PERIODREQUEST_H
