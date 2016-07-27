#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <QString>
#include <QStringList>

class IdGenerator
{
	public:
		IdGenerator();

		operator QString();

	private:
		QStringList m_ids;
};

#endif // IDGENERATOR_H
