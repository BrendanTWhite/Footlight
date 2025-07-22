#ifndef FIXTURE_H
#define FIXTURE_H

#include <QString>

class Fixture
{
private:
    int m_id;
    QString m_name;
    int m_universe;
    int m_channel;

public:
    Fixture(int universe, int channel, QString name);

    int id() const;

    QString name() const;
    void setName(const QString &newName);

    int universe() const;
    void setUniverse(int newUniverse);

    int channel() const;
    void setChannel(int newChannel);
};

#endif // FIXTURE_H
