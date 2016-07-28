#ifndef IOUTPUTHANDLER_H
#define IOUTPUTHANDLER_H

#include "QStringEx.h"

class IOutputHandler
{
	public:
		template<class ...T>
		void say(const QString &format, T& ...arguments) const
		{
			const QString &string = QStringEx::format(format, arguments...);

			say(string);
		}

		template<class ...T>
		void notice(const QString &target, const QString &format, T& ...arguments) const
		{
			const QString &string = QStringEx::format(format, arguments...);

			notice(target, string);
		}

		template<class ...T>
		void message(const QString &target, const QString &format, T& ...arguments) const
		{
			const QString &string = QStringEx::format(format, arguments...);

			message(target, string);
		}

		virtual void say(const QString &message) const = 0;
		virtual void act(const QString &action) const = 0;
		virtual void notice(const QString &target, const QString &notice) const = 0;
		virtual void message(const QString &target, const QString &message) const = 0;

};

#endif // IOUTPUTHANDLER_H
