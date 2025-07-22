#include "fixture.h"

#include <QtDebug>
#include <QString>

Fixture::Fixture(int universe, int channel, QString name) {
    m_id = 1234;
    m_universe = universe;
    m_channel = channel;
    m_name = name;
}

int Fixture::getId() { return m_id; }                               // getter for ID

int Fixture::getUniverse() { return m_universe; }                   // getter for universe
void Fixture::setUniverse(int universe) { m_universe = universe; }  // setter for universe

int Fixture::getChannel() { return m_channel; }                     // getter for channel
void Fixture::setChannel(int channel) { m_channel = channel; }      // setter for channel

QString Fixture::getName() { return m_name; }                       // getter for name
void Fixture::setName(QString name) { m_name = name; }              // setter for name
