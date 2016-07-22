#ifndef RECENTTRACKSRESPONSE_H
#define RECENTTRACKSRESPONSE_H

#include <QObject>

class RecentTracks;

class RecentTracksResponse : public QObject
{
	Q_OBJECT

	Q_PROPERTY(RecentTracks *recenttracks READ recentTracks WRITE setRecentTracks)

	public:
		Q_INVOKABLE RecentTracksResponse();

		RecentTracks *recentTracks() const;
		void setRecentTracks(RecentTracks *recentTracks);

	private:
		RecentTracks *m_recentTracks;
};

#endif // RECENTTRACKSRESPONSE_H
