#include "fixturegroupitem.h"

FixtureGroupItem::FixtureGroupItem(FixtureGroup* fg, Fixture* f)
    : QObject{fg}
{
    this->setParent(fg);
    m_fixturegroup = fg;
    m_fixture = f;
}

FixtureGroupItem::~FixtureGroupItem()
{
    qDebug() << "~ FixtureGroupItem";
}

QString FixtureGroupItem::fixtureGroupName()
{
    if (this->m_fixturegroup) {
        return this->m_fixturegroup->name();
    } else {
        return "Can't find that fixture group";
    }
}

QString FixtureGroupItem::fixtureName()
{
    if (this->m_fixture) {
        return this->m_fixture->name();
    } else {
        return "Can't find that fixture";
    }
}
