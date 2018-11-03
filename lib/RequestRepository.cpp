#include "RequestRepository.h"

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
#include "requests/YouTubeUrlRequest.h"
#include "requests/LastPlayedRequest.h"
#include "requests/WeekRequest.h"
#include "requests/MonthRequest.h"
#include "requests/YearRequest.h"
#include "requests/StatusRequest.h"
#include "requests/HelpRequest.h"

RequestRepository::RequestRepository()
{
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
	attach<YouTubeUrlRequest>();
	attach<LastPlayedRequest>();
	attach<WeekRequest>();
	attach<MonthRequest>();
	attach<YearRequest>();
	attach<StatusRequest>();
	attach<HelpRequest>();
}

QList<IRequest *> RequestRepository::requests() const
{
	return m_requests.toList();
}
