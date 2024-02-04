#include <Quotient/user.h>

#include "MatrixHandler.h"

MatrixHandler::MatrixHandler()
{
	connect(&m_connection, &Quotient::Connection::loginError, this, &MatrixHandler::onLoginError);
	connect(&m_connection, &Quotient::Connection::networkError, this, &MatrixHandler::onNetworkError);
	connect(&m_connection, &Quotient::Connection::connected, this, &MatrixHandler::onConnected);
	connect(&m_connection, &Quotient::Connection::loadedRoomState, this, &MatrixHandler::onLoadedRoomState);
	connect(&m_connection, &Quotient::Connection::syncDone, this, &MatrixHandler::onSyncDone);
	connect(&m_connection, &Quotient::Connection::syncError, this, &MatrixHandler::onSyncError);

	for (auto channel : qEnvironmentVariable("CHANNELS").split(";"))
	{
		qDebug() << "DEBUG:" << "joining room" << channel;

		m_channels.emplace_back(channel, *this, m_requestRepository);
	}
}

void MatrixHandler::setHomeserver(const QUrl &homeserver)
{
	m_connection.setHomeserver(homeserver);
}

void MatrixHandler::loginWithPassword(const QString &user, const QString &password, const QString &deviceName)
{
	m_connection.loginWithPassword(user, password, deviceName);
}

void MatrixHandler::onConnected()
{
	qDebug() << "NOTICE" << "Connected";

	m_connection.sync();

	for (auto& channel : m_channels)
	{
		m_connection.joinRoom(channel.subject);
	}
}

void MatrixHandler::onLoadedRoomState(Quotient::Room *room)
{
	if (auto channel = channel_for(room->canonicalAlias()))
	{
		qDebug() << "DEBUG:" << "joined room" << room->canonicalAlias();

		channel->outputHandler.setRoom(room);

		connect(room, &Quotient::Room::aboutToAddNewMessages, this, [channel, room, this](Quotient::RoomEventsRange events) {
			onAboutToAddNewMessages(events, channel, room);
		});
	}
	else
	{
		qDebug() << "ERROR" << "no channel for room id" << room->canonicalAlias();
	}
}

void MatrixHandler::onSyncDone()
{
	m_connection.sync(10000);
}

void MatrixHandler::onLoginError(QString message, QString details)
{
	qDebug() << "ERROR" << message << details;
}

void MatrixHandler::onNetworkError(QString message, QString details, int retriesTaken, int nextRetryInMilliseconds)
{
	Q_UNUSED(retriesTaken);
	Q_UNUSED(nextRetryInMilliseconds);

	qDebug() << "ERROR" << message << details;
}

void MatrixHandler::onSyncError(QString message, QString details)
{
	qDebug() << "ERROR" << message << details;
}

void MatrixHandler::onAboutToAddNewMessages(Quotient::RoomEventsRange events, channel *channel, Quotient::Room* room)
{
	for (auto &event : events)
	{
		auto message = dynamic_cast<Quotient::RoomMessageEvent *>(event.get());

		if (message)
		{
			auto senderId = message->senderId();
			auto content = message->plainBody();
			auto who = m_connection.user(senderId)->name(room);

			channel->messageHandler.handle(who, content);
		}
	}
}
