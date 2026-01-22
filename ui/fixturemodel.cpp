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
    return local_fixtures.count();
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

// QList<Fixture *> FixtureModel::fixtures() const
// {
//     Show* s = qobject_cast<ShowWindow*>(this->parent())->getShow();
//     return s->findChildren<Fixture *>();
// }

void FixtureModel::addFixture(QString name)
{
    // insert new fixture in local_fixtures
    // Fixture* f = new Fixture (this, 1, 1, "Potato");
    // local_fixtures( Fixture(this, 1, 1, "Potato") );


    beginInsertRows(QModelIndex(), local_fixtures.size(), local_fixtures.size());
    local_fixtures.append(
        {name, number}
        );
    endInsertRows();


}
