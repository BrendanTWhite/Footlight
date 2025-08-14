#ifndef FIXTUREMODEL_H
#define FIXTUREMODEL_H

#include <QAbstractTableModel>

#include "../models/fixture.h"

class FixtureModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit FixtureModel(QObject *parent);
    ~FixtureModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

signals:
};

#endif // FIXTUREMODEL_H
