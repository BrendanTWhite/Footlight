#ifndef FIXTURE_H
#define FIXTURE_H

#include <QtDebug>
#include <QString>
#include <QObject>

#include "show.h"

class Fixture : public QObject
{
    Q_OBJECT

public:
    explicit Fixture(Show *parent, int universe, int channel, QString name);
    ~Fixture();

    int id() const;

    QString name() const;
    void setName(const QString &newName);

    int universe() const;
    void setUniverse(int newUniverse);

    int channel() const;
    void setChannel(int newChannel);


private:
    int m_id;
    QString m_name;
    int m_universe;
    int m_channel;

};

#endif // FIXTURE_H
