#ifndef SHOW_H
#define SHOW_H

#include <QtDebug>
#include <QString>
#include <QObject>
#include <atomic>
#include <QCoreApplication>
#include <QPointer>

#include "fixture.h"
#include "fixturegroup.h"

class Show : public QObject
{
    Q_OBJECT

public:
    explicit Show(QString name, long override_id = NULL);
    ~Show();

    long id() const;

    QString name() const;
    void setName(const QString &newName);

    void addNewFixture();

private:
    long m_id;
    QString m_name;

    QList<Fixture> fixtures;
    QList<FixtureGroup> groups;

signals:
};

#endif // SHOW_H
