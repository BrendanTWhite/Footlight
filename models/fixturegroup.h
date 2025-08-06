#ifndef FIXTUREGROUP_H
#define FIXTUREGROUP_H

#include <QObject>

class fixtureGroup : public QObject
{
    Q_OBJECT
public:
    explicit fixtureGroup(QObject *parent = nullptr);

signals:
};

#endif // FIXTUREGROUP_H
