#ifndef TAGSREQUEST_H
#define TAGSREQUEST_H

#include "IRequest.h"

class TagsRequest : public IRequest
{
	public:
		QString trigger() const override;

		RequestResponse invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context) override;
};

#endif // TAGSREQUEST_H
