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

    int getId();              // getter for ID

    int getUniverse();              // getter for universe
    void setUniverse(int universe);    // setter for universe

    int getChannel();               // getter for channel
    void setChannel(int channel);       // setter for channel

    QString getName();            // getter for name
    void setName(QString name);     // setter for name
};

#endif // FIXTURE_H
