#include "show.h"

Show::Show(QObject *parent, QString name, long override_id)
    : QObject{parent}
{
    static std::atomic_long m_next_id = 1;

    if (override_id > 0) {
        m_next_id = override_id;
    }

    m_id = m_next_id++;
    m_name = name;
}

Show::~Show()
{
    qDebug() << "~ Show" << this->m_id << this->m_name;
}

long Show::id() const
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

