#include "OutputHandler.h"
#include "MatrixHandler.h"
#include "Channel.h"

OutputHandler::OutputHandler(MatrixHandler &matrixHandler, Channel &channel)
	: m_matrixHandler(matrixHandler)
	, m_channel(channel)
{
}

void OutputHandler::say(const QString &message) const
{
	m_room->postHtmlMessage(message, message, MessageEventType::Text);
}

void OutputHandler::act(const QString &action) const
{
	Q_UNUSED(action);
}

void OutputHandler::notice(const QString &target, const QString &notice) const
{
	Q_UNUSED(target);
	Q_UNUSED(notice);
}

void OutputHandler::message(const QString &target, const QString &message) const
{
	Q_UNUSED(target);
	Q_UNUSED(message);
}

void OutputHandler::setRoom(Room *room)
{
	m_room = room;
}
