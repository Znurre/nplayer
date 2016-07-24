#include "NowPlayingRequest.h"
#include "RequestInvocationContext.h"
#include "RequestHandler.h"
#include "IOutputHandler.h"
#include "RecentTracksResponse.h"
#include "RecentTracks.h"
#include "Artist.h"

#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlEngine>

#include "components/ITemplateComponent.h"

NowPlayingRequest::NowPlayingRequest()
{
	qRegisterMetaType<RecentTracksResponse *>();
	qRegisterMetaType<RecentTracks *>();
	qRegisterMetaType<Artist *>();
}

QString NowPlayingRequest::trigger() const
{
	return ".np";
}

void NowPlayingRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(arguments);
	Q_UNUSED(who);

	Track *nowPlaying = getNowPlaying();

	if (nowPlaying)
	{
		const IOutputHandler &outputHandler = context.outputHandler();

		QQmlEngine engine;
		QQmlComponent component(&engine, "shared/templates/NowPlaying.qml");

		QQmlContext *context = engine.rootContext();
		context->setContextObject(nowPlaying);

		ITemplateComponent *tc = (ITemplateComponent *)component.create();

		if (!tc)
		{
			qDebug() << component.errorString();

			return;
		}

		const QString &text = tc->render();

		outputHandler.say(text);
	}
}

Track *NowPlayingRequest::getNowPlaying() const
{
	const RequestHandler requestHandler;
	const RecentTracks *recentTracks = requestHandler
		.get<RecentTracks>("user.getRecentTracks"
			, as::limit = "1"
			, as::user = "Znurre"
		);

	if (recentTracks)
	{
		for (Track *track : recentTracks->tracks())
		{
			if (track->nowPlaying())
			{
				return track;
			}
		}
	}

	return nullptr;
}
