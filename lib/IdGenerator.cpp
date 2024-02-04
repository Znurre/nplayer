#include <QDateTime>

#include "IdGenerator.h"

IdGenerator::IdGenerator()
{
	QString source;

	for (int offset = 48; offset < (48 + 97); offset += (97 - 48))
	{
		for (int i = 0; i < (offset == 48 ? 10 : 26); i++)
		{
			source += (char)(i + offset);
		}
	}

	for (int a = 0; a < source.length(); a++)
	for (int b = 0; b < source.length(); b++)
	for (int c = 0; c < source.length(); c++)
	for (int d = 0; d < source.length(); d++)
	{
		QString id;

		id += source[a];
		id += source[b];
		id += source[c];
		id += source[d];

		m_ids << id;
	}
}

IdGenerator::operator QString()
{
	const auto &dateTime = QDateTime::currentDateTime();
	const auto seed = dateTime.toMSecsSinceEpoch();

	srand(seed);

	const auto index = rand() % m_ids.count();

	return m_ids.takeAt(index);
}
