#include "RequestProvider.h"

#include "requests/LoadRequest.h"
#include "requests/UnloadRequest.h"

RequestProvider::RequestProvider()
{

}

RequestDefinitionBuilder &RequestProvider::definition(RequestDefinitionBuilder &builder)
{
	return builder
		.request<LoadRequest>()
		.request<UnloadRequest>();
}
