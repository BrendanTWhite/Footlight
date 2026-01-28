#ifndef FIXTURE_H
#define FIXTURE_H

#include <QtDebug>
#include <QString>
#include <QObject>
#include <atomic>

#include "show.h"

class Fixture // : public QObject
{
    // Q_OBJECT

public:
    explicit Fixture(Show *parent, int universe, int channel, QString name, long override_id = NULL);
    explicit Fixture(QString name, QString universe, QString channel);
    ~Fixture();

    long id() const;

    // QString name() const;
    // void setName(const QString &newName);

    // int universe() const;
    // void setUniverse(int newUniverse);

    // int channel() const;
    // void setChannel(int newChannel);


public: // should be private!
// private: // should be private!
    long m_id;
    QString m_name;
    QString m_universe; // int
    QString m_channel; // int

};

#endif // FIXTURE_H
