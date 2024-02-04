#ifndef MATRIXHANDLER_H
#define MATRIXHANDLER_H

#include <Quotient/connection.h>

#include "OutputHandler.h"
#include "RequestRepository.h"
#include "MessageHandler.h"
#include "Channel.h"

class MatrixHandler;

struct channel
{
	channel(const QString& name, MatrixHandler& matrixHandler, RequestRepository& requestRepository)
		: subject(name)
		, outputHandler(matrixHandler, subject)
		, messageHandler(outputHandler, requestRepository)
	{
	}

	Channel subject;
	OutputHandler outputHandler;
	MessageHandler messageHandler;
};

class MatrixHandler : public QObject
{
	public:
		MatrixHandler();

		void setHomeserver(const QUrl &homeserver);
		void loginWithPassword(const QString& user, const QString& password, const QString& deviceName);

	private:
		void onConnected();
		void onLoadedRoomState(Quotient::Room *room);
		void onSyncDone();
		void onLoginError(QString message, QString details);
		void onNetworkError(QString message, QString details, int retriesTaken, int nextRetryInMilliseconds);
		void onSyncError(QString message, QString details);
		void onAboutToAddNewMessages(Quotient::RoomEventsRange events, channel *channel, Quotient::Room *room);

		channel* channel_for(const QString& name)
		{
			for (auto& channel : m_channels)
			{
				if (channel.subject == name)
				{
					return &channel;
				}
			}

			return nullptr;
		}

		std::list<channel> m_channels;

		RequestRepository m_requestRepository;

		Quotient::Connection m_connection;
};

#endif // MATRIXHANDLER_H
