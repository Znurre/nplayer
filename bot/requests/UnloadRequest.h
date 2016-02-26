#ifndef UNLOADREQUEST_H
#define UNLOADREQUEST_H

#include "IRequest.h"

class UnloadRequest : public IRequest
{
	public:
		UnloadRequest();

		QString trigger() const override;

		void invoke(const QStringList &arguments, const RequestInvocationContext &context) override;
};

#endif // UNLOADREQUEST_H
