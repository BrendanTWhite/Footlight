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
    // ShowWindow* show = this->show();
    // if (show == nullptr) {
    //     qDebug() << "show is nullptr";
    // }
    qDebug() << "fm rc 1";
    qDebug() << this->objectName(); // empty string
    qDebug() << "fm rc 2";
    qDebug() << this->parent()->objectName(); // ShowWindow
    ShowWindow* sw = qobject_cast<ShowWindow*>(this->parent());
    qDebug() << "fm rc 3";

    // ShowWindow* show = this->show();
    if (sw == nullptr) {
        qDebug() << "ERROR - sw is nullptr";
        exit(EXIT_FAILURE);
    }
    qDebug() << sw->objectName(); // empty string
    qDebug() << "fm rc 4";

    Show* s = sw->show();
    qDebug() << "fm rc 5";

    if (s == nullptr) {
        qDebug() << "ERROR - s is nullptr"; // yep, it's nullptr
        exit(EXIT_FAILURE);
    }
    qDebug() << s->objectName(); // crashes; s is nullptr
    qDebug() << "fm rc 6";

    qDebug() << s->name();
    qDebug() << "fm rc 7";
    QList<Fixture *> fixtures = s->findChildren<Fixture *>();
    qDebug() << "fm rc 8";
    // return fixtures.count();
    return 6;
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

// ShowWindow* FixtureModel::sw() const
// {
//     return qobject_cast<ShowWindow*>(this->parent());
// }


