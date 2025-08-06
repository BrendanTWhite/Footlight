#ifndef FIXTUREGROUP_H
#define FIXTUREGROUP_H

#include <QString>
#include <QObject>

#include "show.h"

class FixtureGroup : public QObject
{
    Q_OBJECT

public:
    explicit FixtureGroup(Show *parent, QString name );

    int id() const;

    QString name() const;
    void setName(const QString &newName);

private:
    int m_id;
    QString m_name;

signals:
};

#endif // FIXTUREGROUP_H
