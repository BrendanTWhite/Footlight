#include "fixturemodel.h"

FixtureModel::FixtureModel(QObject *parent)
    : QAbstractTableModel{parent}
{}

FixtureModel::~FixtureModel()
{}



int FixtureModel::rowCount(const QModelIndex & /*parent*/) const
{
    return 6;
}

int FixtureModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 4;
}

QVariant FixtureModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        return QString("r%1c%2")
            .arg(index.row() + 1)
            .arg(index.column() +1);

    return QVariant();
}

QVariant FixtureModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("first");
        case 1:
            return QString("second");
        case 2:
            return QString("third");
        case 3:
            return QString("fourth");
        }
    }
    return QVariant();
}
