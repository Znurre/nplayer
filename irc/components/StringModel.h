#ifndef STRINGMODEL_H
#define STRINGMODEL_H

#include <QAbstractListModel>
#include <QJsonSerializer>

class StringModel : public QAbstractListModel
{
	Q_OBJECT

	Q_PROPERTY(Array<QString> values READ values WRITE setValues NOTIFY valuesChanged)

	public:
		Array<QString> values() const;
		void setValues(const Array<QString> &values);

		int rowCount(const QModelIndex &parent) const override;

		QHash<int, QByteArray> roleNames() const override;
		QVariant data(const QModelIndex &index, int role) const override;

	private:
		Array<QString> m_values;

	signals:
		void valuesChanged();
};

#endif // STRINGMODEL_H
