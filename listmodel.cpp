#include "listmodel.h"

/*********************** CListModel *****************************/
CListModel::CListModel()
{

}

CListModel::~CListModel()
{

}

void CListModel::addData(const QString &unit)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_names.append(unit);
    endInsertRows();
}

int CListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_names.count();
}

QVariant CListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_names.count())
        return QVariant();

    const QString &name = m_names[index.row()];
    if (role == NameRole)
        return name;
    return QVariant();
}

QHash<int, QByteArray> CListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    return roles;
}
/*********************** CListModel *****************************/


/******************** FilterProxyModel **************************/
FilterProxyModel::FilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    setSortOrder(false);
}

FilterProxyModel::~FilterProxyModel()
{

}

void FilterProxyModel::setFilterString(QString string)
{
    this->setFilterCaseSensitivity(Qt::CaseInsensitive);
    this->setFilterFixedString(string);
}

void FilterProxyModel::setSortOrder(bool checked)
{
    if(checked)
    {
        this->sort(0, Qt::DescendingOrder);
    }
    else
    {
        this->sort(0, Qt::AscendingOrder);
    }
}
/******************** FilterProxyModel **************************/
