#include "RequestRepository.h"

#include "requests/HelloWorldRequest.h"
#include "requests/NowPlayingRequest.h"
#include "requests/AlbumRequest.h"
#include "requests/ArtistRequest.h"
#include "requests/TrackRequest.h"
#include "requests/TagRequest.h"
#include "requests/AccountRequest.h"
#include "requests/UserRequest.h"
#include "requests/LastFmUrlRequest.h"
#include "requests/ArtistsRequest.h"
#include "requests/PingRequest.h"
#include "requests/TagsRequest.h"
#include "requests/SpotifyUrlRequest.h"

RequestRepository::RequestRepository()
{
	attach<HelloWorldRequest>();
	attach<NowPlayingRequest>();
	attach<AlbumRequest>();
	attach<ArtistRequest>();
	attach<TrackRequest>();
	attach<TagRequest>();
	attach<AccountRequest>();
	attach<UserRequest>();
	attach<LastFmUrlRequest>();
	attach<ArtistsRequest>();
	attach<PingRequest>();
	attach<TagsRequest>();
	attach<SpotifyUrlRequest>();
}
