#ifndef FIXTUREGROUPITEM_H
#define FIXTUREGROUPITEM_H

#include <QtDebug>
#include <QObject>
#include <QString>
#include <atomic>

#include "show.h"
#include "fixture.h"
#include "fixturegroup.h"

class FixtureGroupItem : public QObject
{
    Q_OBJECT

public:
    // explicit FixtureGroupItem(FixtureGroup *parent, Fixture *fixture);
    explicit FixtureGroupItem(FixtureGroup *parent);
    ~FixtureGroupItem();

    long id() const;

    QString name() const;
    void setName(const QString &newName);

    Fixture* fixture() const;

private:
    long m_id;
    QString m_name;
    Fixture* m_fixture;

signals:
};

#endif // FIXTUREGROUPITEM_H
