#include "fixture.h"

int Fixture::id() const
{
    return m_id;
}

QString Fixture::name() const
{
    return m_name;
}

void Fixture::setName(const QString &newName)
{
    m_name = newName;
}

int Fixture::universe() const
{
    return m_universe;
}

void Fixture::setUniverse(int newUniverse)
{
    m_universe = newUniverse;
}

int Fixture::channel() const
{
    return m_channel;
}

void Fixture::setChannel(int newChannel)
{
    m_channel = newChannel;
}


Fixture::Fixture(Show *parent, int universe, int channel, QString name)
    : QObject{parent}
{
    m_id = 1234;
    m_universe = universe;
    m_channel = channel;
    m_name = name;
}

Fixture::~Fixture()
{
    qDebug() << "Deconstructing Fixture " << this->m_name;
}
