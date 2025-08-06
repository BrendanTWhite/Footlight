#include "fixturegroup.h"

FixtureGroup::FixtureGroup(Show *parent, QString name)
    : QObject{parent}
{
    m_id = 2345;
    m_name = name;
}

int FixtureGroup::id() const
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

