#include "RequestRepository.h"

#include "requests/HelloWorldRequest.h"
#include "requests/NowPlayingRequest.h"
#include "requests/AlbumRequest.h"
#include "requests/ArtistRequest.h"

RequestRepository::RequestRepository()
{
	attach<HelloWorldRequest>();
	attach<NowPlayingRequest>();
	attach<AlbumRequest>();
	attach<ArtistRequest>();
}
