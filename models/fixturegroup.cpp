#include "fixturegroup.h"

FixtureGroup::FixtureGroup(Show* parent, QString name, long override_id)
    : QObject{}
{
    static std::atomic_long m_next_id = 1;

    if (override_id) {
        m_next_id = override_id;
    }

    m_id = m_next_id++;
    m_name = name;
    this->setObjectName(name);
}

FixtureGroup::~FixtureGroup()
{
    qDebug() << "~ FixtureGroup" << this->m_id << this->m_name;
}

long FixtureGroup::id() const
{
    return m_id;
}

QString FixtureGroup::name() const
{
    return m_name;
}

void FixtureGroup::setName(const QString &newName)
{
    m_name = newName;
}

