#include "fixturemodel.h"


// This is what Qt calls the "model", which is
// the glue between the object (or QList of objects)
// and the UI grid.

FixtureModel::FixtureModel(QList<Fixture>& fixtures, ShowWindow *parent)
    : QAbstractTableModel(parent), list_ref_in_model(fixtures)
{}

FixtureModel::~FixtureModel()
{}

#include "../models/show.h"
#include "showwindow.h"

int FixtureModel::rowCount(const QModelIndex & parent) const
{
    return parent.isValid() ? 0 : list_ref_in_model.size();
}

int FixtureModel::columnCount(const QModelIndex & parent) const
{
    return parent.isValid() ? 0 : 3;
}

QVariant FixtureModel::data(const QModelIndex &index, int role) const
{

    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    Fixture fixture = list_ref_in_model.at(index.row());
    if (index.column() == 0)
        return fixture.m_name;
    else if (index.column() == 1)
        return fixture.m_universe;
    else if (index.column() == 2)
        return fixture.m_channel;
    else return QVariant();

}

QVariant FixtureModel::headerData(int column_id, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return columnMap.value(column_id);
    }
    return QVariant();
}




void FixtureModel::addFixture(const QString& name, const QString& universe, const QString &channel) {
    beginInsertRows(QModelIndex(), list_ref_in_model.size(), list_ref_in_model.size());
    list_ref_in_model.append(Fixture{name, universe, channel});
    endInsertRows();
}

void FixtureModel::removeFixture(int row) {
    if (row >= 0 && row < list_ref_in_model.size()) {
        beginRemoveRows(QModelIndex(), row, row);
        list_ref_in_model.removeAt(row);
        endRemoveRows();
    }
}

bool FixtureModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    Fixture &fixture = list_ref_in_model[index.row()];

    if (index.column() == 0) {
        fixture.m_name = value.toString();
    } else if (index.column() == 1) {
        fixture.m_universe = value.toString();
    } else if (index.column() == 2) {
        fixture.m_channel = value.toString();
    }

    emit dataChanged(index, index, {role});
    return true;
}
