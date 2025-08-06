#ifndef FIXTUREGROUP_H
#define FIXTUREGROUP_H

#include <QtDebug>
#include <QObject>
#include <QString>
#include <atomic>

#include "show.h"

class FixtureGroup : public QObject
{
    Q_OBJECT

public:
    explicit FixtureGroup(Show *parent, QString name, long override_id = 1 );
    ~FixtureGroup();

    long id() const;

    QString name() const;
    void setName(const QString &newName);

private:
    long m_id;
    QString m_name;

signals:
};

#endif // FIXTUREGROUP_H
