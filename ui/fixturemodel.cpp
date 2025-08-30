#include "fixturemodel.h"

FixtureModel::FixtureModel(QObject *parent)
    : QAbstractTableModel{parent}
{}

FixtureModel::~FixtureModel()
{}

#include "../models/show.h"
#include "showwindow.h"

int FixtureModel::rowCount(const QModelIndex & /*parent*/) const
{
    return fixtures().count();
}

int FixtureModel::columnCount(const QModelIndex & /*parent*/) const
{
    return columnMap.size();
}

QVariant FixtureModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return QString("r%1 c%2")
            .arg(index.row())
            .arg(index.column());
    }

    return QVariant();
}

QVariant FixtureModel::headerData(int column_id, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return columnMap.value(column_id);
    }
    return QVariant();
}

QList<Fixture *> FixtureModel::fixtures() const
{
    Show* s = qobject_cast<ShowWindow*>(this->parent())->getShow();
    return s->findChildren<Fixture *>();
}

