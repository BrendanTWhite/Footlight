#include "fixturegroupitem.h"

FixtureGroupItem::FixtureGroupItem(FixtureGroup *parent)
    : QObject{parent}
{

}

FixtureGroupItem::~FixtureGroupItem()
{
    // qDebug() << "~ FixtureGroupItem " << this->m_name;
    qDebug() << "~ FixtureGroupItem INSERT NAME HERE ";
}
