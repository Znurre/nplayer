#include "StringModel.h"

Array<QString> StringModel::values() const
{
	return m_values;
}

void StringModel::setValues(const Array<QString> &values)
{
	m_values = values;

	qDebug() << "setValues" << values.count();

	emit layoutChanged();
}

int StringModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);

	return m_values.count();
}

QHash<int, QByteArray> StringModel::roleNames() const
{
	return
	{
		{ Qt::UserRole, "value" }
	};
}

QVariant StringModel::data(const QModelIndex &index, int role) const
{
	if (role == Qt::UserRole)
	{
		const int row = index.row();

		return m_values[row];
	}

	return QVariant();
}
