#include "fixturegroupitem.h"

FixtureGroupItem::FixtureGroupItem(FixtureGroup *parent)
    : QObject{parent}
{

}

FixtureGroupItem::~FixtureGroupItem()
{
    // qDebug() << "Deconstructing FixtureGroupItem " << this->m_name;
    qDebug() << "Deconstructing FixtureGroupItem INSERT NAME HERE ";
}
