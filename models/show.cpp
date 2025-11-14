#include "show.h"

#include "fixture.h"

#include "../ui/showwindow.h"

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
    this->setObjectName(name);
}

void Show::addNewFixture(){
    ShowWindow* myShowWindow = qobject_cast<ShowWindow *>(this->parent());
    QPointer<Fixture> f = new Fixture{this, 0, 0, "Show::addNewFixture()"};

    myShowWindow->dumpObjectTree();

    myShowWindow->update();
    qDebug() << "fixture added";
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

