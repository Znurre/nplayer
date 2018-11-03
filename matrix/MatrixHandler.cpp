#include <user.h>

#include "MatrixHandler.h"

MatrixHandler::MatrixHandler()
	: m_channel("#np:matrix.znurre.com")
	, m_outputHandler(*this, m_channel)
	, m_messageHandler(m_outputHandler, m_requestRepository)
{
	connect(this, &Connection::loginError, this, &MatrixHandler::onLoginError);
	connect(this, &Connection::networkError, this, &MatrixHandler::onNetworkError);
	connect(this, &Connection::connected, this, &MatrixHandler::onConnected);
	connect(this, &Connection::loadedRoomState, this, &MatrixHandler::onLoadedRoomState);
	connect(this, &Connection::syncDone, this, &MatrixHandler::onSyncDone);
	connect(this, &Connection::syncError, this, &MatrixHandler::onSyncError);
}

void MatrixHandler::onConnected()
{
	qDebug() << "NOTICE" << "Connected";

	sync();

	joinRoom(m_channel);
}

void MatrixHandler::onLoadedRoomState(Room *room)
{
	Q_UNUSED(room);

	connect(room, &Room::aboutToAddNewMessages, this, &MatrixHandler::onAboutToAddNewMessages);

	m_outputHandler.setRoom(room);
}

void MatrixHandler::onSyncDone()
{
	sync(10000);
}

void MatrixHandler::onLoginError(QString message, QByteArray details)
{
	qDebug() << "ERROR" << message << details;
}

void MatrixHandler::onNetworkError(QString message, QByteArray details, int retriesTaken, int nextRetryInMilliseconds)
{
	Q_UNUSED(retriesTaken);
	Q_UNUSED(nextRetryInMilliseconds);

	qDebug() << "ERROR" << message << details;
}

void MatrixHandler::onSyncError(QString message, QByteArray details)
{
	qDebug() << "ERROR" << message << details;
}

void MatrixHandler::onAboutToAddNewMessages(RoomEventsRange events)
{
	for (auto &event : events)
	{
		RoomMessageEvent *message = dynamic_cast<RoomMessageEvent *>(event.get());

		if (message)
		{
			const QString &senderId = message->senderId();
			const QString &content = message->plainBody();
			const QString &who = user(senderId)->name();

			m_messageHandler.handle(who, content);
		}
	}
}
