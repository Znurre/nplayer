#ifndef REQUESTPROVIDER_H
#define REQUESTPROVIDER_H

#include "IRequestProvider.h"

class RequestProvider : public IRequestProvider
{
	public:
		RequestProvider();

		RequestDefinitionBuilder &definition(RequestDefinitionBuilder &builder) override;
};

#endif // REQUESTPROVIDER_H
