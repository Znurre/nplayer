#ifndef REQUESTRESPONSE_H
#define REQUESTRESPONSE_H

#include "IInformationResource.h"

class RequestResponse
{
	public:
		RequestResponse(const QString &templateName, IInformationResource *resource);

		QString templateName() const;
		IInformationResource *resource() const;

	private:
		QString m_templateName;
		IInformationResource *m_resource;
};

#endif // REQUESTRESPONSE_H
