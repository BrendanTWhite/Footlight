#include "fixturegroup.h"

FixtureGroup::FixtureGroup(Show *parent, QString name)
    : QObject{parent}
{
    m_id = 2345;
    m_name = name;
}
