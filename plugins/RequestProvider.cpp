#include "HelloWorldRequest.h"
#include "NowPlayingRequest.h"
#include "RequestProvider.h"

RequestProvider::RequestProvider()
{

}

RequestDefinitionBuilder &RequestProvider::definition(RequestDefinitionBuilder &builder)
{
	return builder
		.request<HelloWorldRequest>()
		.request<NowPlayingRequest>()
		;
}
