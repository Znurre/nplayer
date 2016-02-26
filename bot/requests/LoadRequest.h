#ifndef LOADREQUEST_H
#define LOADREQUEST_H

#include "IRequest.h"

class LoadRequest : public IRequest
{
	public:
		LoadRequest();

		QString trigger() const override;

		void invoke(const QStringList &arguments, const RequestInvocationContext &context) override;
};

#endif // LOADREQUEST_H
