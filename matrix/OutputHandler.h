#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H

#include <room.h>

#include "IOutputHandler.h"

class MatrixHandler;
class Channel;

using namespace QMatrixClient;

class OutputHandler : public IOutputHandler
{
	public:
		OutputHandler(MatrixHandler &matrixHandler, Channel &channel);

		void say(const QString &message) const override;
		void act(const QString &action) const override;
		void notice(const QString &target, const QString &notice) const override;
		void message(const QString &target, const QString &message) const override;

		void setRoom(Room *room);

	private:
		Room *m_room;

		MatrixHandler &m_matrixHandler;
		Channel &m_channel;
};

#endif // OUTPUTHANDLER_H
