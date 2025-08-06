#include "show.h"

Show::Show(QObject *parent, QString name)
    : QObject{parent}
{
    m_id = 3456;
    m_name = name;
}

int Show::id() const
{
    return m_id;
}

QString Show::name() const
{
    return m_name;
}

void Show::setName(const QString &newName)
{
    m_name = newName;
}

