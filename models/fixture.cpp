#include "fixture.h"

Fixture::Fixture(Show *parent, int universe, int channel, QString name, long override_id)
    : QObject{parent}
{
    static std::atomic_long m_next_id = 1;
    if (override_id) {
        m_next_id = override_id;
    }
    m_id = m_next_id++;

    m_universe = universe;
    m_channel = channel;
    m_name = name;
}

Fixture::~Fixture()
{
    qDebug() << "~ Fixture" << this->m_id << this->m_name;
}


long Fixture::id() const
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
