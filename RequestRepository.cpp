#include "RequestRepository.h"

#include "requests/HelloWorldRequest.h"
#include "requests/NowPlayingRequest.h"
#include "requests/AlbumRequest.h"
#include "requests/ArtistRequest.h"
#include "requests/TrackRequest.h"
#include "requests/TagRequest.h"

RequestRepository::RequestRepository()
{
	attach<HelloWorldRequest>();
	attach<NowPlayingRequest>();
	attach<AlbumRequest>();
	attach<ArtistRequest>();
	attach<TrackRequest>();
	attach<TagRequest>();
}
