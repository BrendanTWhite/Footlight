#include "show.h"

Show::Show(QString name, long override_id)
    // a Show's parent is always the App
    : QObject{QCoreApplication::instance()}
{
    static std::atomic_long m_next_id = 1;

    if (override_id) {
        m_next_id = override_id;
    }

    m_id = m_next_id++;
    m_name = name;
}

void Show::addNewFixture(){
    qDebug() << "batman";
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

