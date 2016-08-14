#include "UserMapper.h"

const QString FILENAME = "users.db";

UserMapper::UserMapper()
{
	QFile file(FILENAME);
	QDataStream stream(&file);

	if (file.open(QIODevice::ReadOnly))
	{
		stream >> m_mapping;
	}
}

QString UserMapper::map(const QString &nickname)
{
	return m_mapping.value(nickname, nickname);
}

void UserMapper::store(const QString &nickname, const QString &username)
{
	m_mapping[nickname] = username;

	QFile file(FILENAME);
	QDataStream stream(&file);

	if (file.open(QIODevice::WriteOnly))
	{
		stream << m_mapping;
	}
}
