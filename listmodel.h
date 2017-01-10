#ifndef CLISTMODEL_H
#define CLISTMODEL_H

#include <QAbstractListModel>
#include <QSortFilterProxyModel>

enum Roles {
    NameRole = Qt::UserRole + 1,
};

//List Model
class CListModel : public QAbstractListModel
{
public:
    CListModel();
    ~CListModel();

    void addData(const QString &unit);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QStringList m_names;
};


//Filter proxy model
class FilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:

    FilterProxyModel(QObject* parent = 0);

    ~FilterProxyModel();

    Q_INVOKABLE void setFilterString(QString string);

    Q_INVOKABLE void setSortOrder(bool checked);
};


#endif // CLISTMODEL_H
