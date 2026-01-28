#ifndef FIXTUREMODEL_H
#define FIXTUREMODEL_H

#include <QAbstractTableModel>
#include <QMultiMap>
#include <QString>
#include <QList>
#include <QVariant>
#include <QBrush>

#include "../ui/showwindow.h"
#include "../models/fixture.h"


class FixtureModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit FixtureModel(
        QList<Fixture>& list_ref_in_model_constructor,
        ShowWindow *parent
                          );
    ~FixtureModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void addFixture(const QString &name, const QString &universe, const QString &channel);
    void removeFixture(int row);
    bool setData(
        const QModelIndex &index, const QVariant &value, int role = Qt::EditRole
        ) override;


    // QList<Fixture *> fixtures() const;

signals:


private:

    QList<Fixture>& list_ref_in_model;
    // model has a REFERENCE to the QList

    QMultiMap<int,QString> columnMap = QMultiMap<int,QString>({
        // Indexes must be zero-based incrementing integers
        {0,"Name"},
        {1,"Universe"},
        {2,"DMX Channel"},
        // {3,"Area"},
        // {4,"Type"},
    });

};

#endif // FIXTUREMODEL_H
