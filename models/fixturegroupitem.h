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
    explicit FixtureGroupItem(Show *parent, FixtureGroup *fg, Fixture *f);
    ~FixtureGroupItem();

    QString fixtureGroupName();
    QString fixtureName();

    long id() const;

    QString name() const;
    void setName(const QString &newName);

    Fixture* fixture() const;

private:
    long m_id;
    QString m_name;
    // QPointer<Fixture> m_fixture = nullptr;
    Fixture *m_fixture;
    FixtureGroup *m_fixturegroup;

signals:
};

#endif // FIXTUREGROUPITEM_H
