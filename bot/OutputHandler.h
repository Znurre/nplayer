#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H

#include "IOutputHandler.h"

class Channel;
class IrcHandler;

class OutputHandler : public IOutputHandler
{
	public:
		OutputHandler(IrcHandler &ircHandler, Channel &channel);

		void say(const QString &message) const override;
		void act(const QString &action) const override;
		void notice(const QString &target, const QString &notice) const override;
		void message(const QString &target, const QString &message) const override;

	private:
		IrcHandler &m_ircHandler;
		Channel &m_channel;
};

#endif // OUTPUTHANDLER_H
