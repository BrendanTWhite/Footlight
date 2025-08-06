#ifndef FIXTUREGROUPITEM_H
#define FIXTUREGROUPITEM_H

#include <QtDebug>
#include <QObject>
#include <QString>

#include "show.h"
#include "fixture.h"
#include "fixturegroup.h"

class FixtureGroupItem : public QObject
{
    Q_OBJECT

public:
    explicit FixtureGroupItem(FixtureGroup *parent);
    ~FixtureGroupItem();

signals:
};

#endif // FIXTUREGROUPITEM_H
