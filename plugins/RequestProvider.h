#ifndef REQUESTPROVIDER_H
#define REQUESTPROVIDER_H

#include "IRequestProvider.h"

class RequestProvider : public IRequestProvider
{
	Q_OBJECT

	Q_INTERFACES(IRequestProvider)

	Q_PLUGIN_METADATA(IID "com.avoidpointer.IRequestProvider")

	public:
		RequestProvider();

		RequestDefinitionBuilder &definition(RequestDefinitionBuilder &builder) override;
};

#endif // REQUESTPROVIDER_H
