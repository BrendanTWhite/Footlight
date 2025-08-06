#include "mainwindow.h"

#include "models/show.h"
#include "models/fixture.h"
#include "models/fixturegroup.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Footlight_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    // from https://github.com/AndreiCherniaev/CMake_variable_to_code/tree/main
    #define CFG(x) #x
    #define CONFIG(x) CFG(x)

    // // from CMAKE
    // qDebug() << "----------------------------------- ";
    // qDebug() << "CMAKE_PROJECT_NAME"        << CONFIG(CMAKE_PROJECT_NAME);
    // qDebug() << "CMAKE_PROJECT_DESCRIPTION" << CONFIG(CMAKE_PROJECT_DESCRIPTION);
    // qDebug() << "CMAKE_PROJECT_VERSION"     << CONFIG(CMAKE_PROJECT_VERSION);

    // // from HF vars in Projects
    // qDebug() << "----------------------------------- ";
    // qDebug() << "HF_ORG_NAME"   << CONFIG(HF_ORG_NAME);
    // qDebug() << "HF_ORG_DOMAIN" << CONFIG(HF_ORG_DOMAIN);
    // qDebug() << "----------------------------------- ";
    // qDebug() << "HF_APP_NAME"           << CONFIG(HF_APP_NAME);
    // qDebug() << "HF_APP_DISPLAY_NAME"   << CONFIG(HF_APP_DISPLAY_NAME);
    // qDebug() << "HF_APP_DESCRIPTION"    << CONFIG(HF_APP_DESCRIPTION);
    // qDebug() << "HF_APP_VERSION"        << CONFIG(HF_APP_VERSION);

    // Set stuff in app
    a.setOrganizationName(CONFIG(HF_ORG_NAME));
    a.setOrganizationDomain(CONFIG(HF_ORG_DOMAIN));

    a.setApplicationName(CONFIG(HF_APP_NAME));
    a.setApplicationDisplayName(CONFIG(HF_APP_DISPLAY_NAME));
    a.setApplicationVersion(CONFIG(HF_APP_VERSION));

    // // from app
    // qDebug() << "----------------------------------- ";
    // qDebug() << "a.organizationName()"      << a.organizationName();
    // qDebug() << "a.organizationDomain()"    << a.organizationDomain();
    // qDebug() << "----------------------------------- ";
    // qDebug() << "a.applicationName()"           << a.applicationName();
    // qDebug() << "a.applicationDisplayName()"    << a.applicationDisplayName();
    // qDebug() << "a.applicationVersion()"        << a.applicationVersion();


    // create a dummy show
    Show show = Show{&a,"Godot Finally Arrives"};

    // create some dummy fixtures
    Fixture f1 = Fixture{&show,1,1,"Fred"};
    Fixture f2 = Fixture{&show,1,2,"George"};
    Fixture f3 = Fixture{&show,1,3,"Tom"};
    Fixture f4 = Fixture{&show,1,4,"Dick"};
    Fixture f5 = Fixture{&show,1,5,"Harry"};

    qDebug() << "----------------------------------- ";

    qDebug() << "Show" << show.name()
             << "has ID" << show.id();

    qDebug() << "Fixture" << f1.name()
             << "is in Universe" << f1.universe()
             << "at Channel" << f1.channel()
             << "and has ID" << f1.id();

    qDebug() << "Fixture" << f5.name()
             << "is in Universe" << f5.universe()
             << "at Channel" << f5.channel()
             << "and has ID" << f5.id();



    MainWindow w;
    w.show();
    return a.exec();
}
