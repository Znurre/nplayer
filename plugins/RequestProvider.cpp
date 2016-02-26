#include "HelloWorldRequest.h"
#include "RequestProvider.h"

RequestProvider::RequestProvider()
{

}

RequestDefinitionBuilder &RequestProvider::definition(RequestDefinitionBuilder &builder)
{
	return builder
		.request<HelloWorldRequest>()
		;
}
