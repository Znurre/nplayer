#ifndef MATRIXHANDLER_H
#define MATRIXHANDLER_H

#include <connection.h>

#include "OutputHandler.h"
#include "RequestRepository.h"
#include "MessageHandler.h"
#include "Channel.h"

using namespace QMatrixClient;

class MatrixHandler : public Connection
{
	public:
		MatrixHandler();

	private:
		void onConnected();
		void onLoadedRoomState(Room *room);
		void onSyncDone();
		void onLoginError(QString message, QByteArray details);
		void onNetworkError(QString message, QByteArray details, int retriesTaken, int nextRetryInMilliseconds);
		void onSyncError(QString message, QByteArray details);
		void onAboutToAddNewMessages(RoomEventsRange events);

		Channel m_channel;
		OutputHandler m_outputHandler;
		RequestRepository m_requestRepository;
		MessageHandler m_messageHandler;
};

#endif // MATRIXHANDLER_H
