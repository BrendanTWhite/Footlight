#ifndef FIXTURE_H
#define FIXTURE_H

#include <QtDebug>
#include <QString>
#include <QObject>
#include <atomic>

#include "show.h"

class Fixture : public QObject
{
    Q_OBJECT

public:
    explicit Fixture(Show *parent, int universe, int channel, QString name, long override_id = 0);
    ~Fixture();

    long id() const;

    QString name() const;
    void setName(const QString &newName);

    int universe() const;
    void setUniverse(int newUniverse);

    int channel() const;
    void setChannel(int newChannel);


private:
    long m_id;
    QString m_name;
    int m_universe;
    int m_channel;

};

#endif // FIXTURE_H
