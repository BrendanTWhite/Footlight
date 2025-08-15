#include "ui/showwindow.h"
#include "ui/neworopenwindow.h"

#include "models/show.h"
#include "models/fixture.h"
#include "models/fixturegroup.h"
#include "models/fixturegroupitem.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QtDebug>
#include <QPointer>

#include <QFileDialog>
#include <QDir>

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
    QPointer<Show> show = new Show{"Godot Finally Arrives"};
    // QPointer<Show> show2 = new Show{"Romeo & Juliet"};

    qDebug() << "----------------------------------- ";
    qDebug() << "Show" << show->id() << show->name();
    // qDebug() << "Show" << show2->id() << show2->name();

    // // Create a QList of fixtures
    // QList<Fixture*> fixtures = {
    //      new Fixture{show, 1, 1, "Fred"},
    //      new Fixture{show, 1, 2, "George"},
    //      new Fixture{show, 1, 3, "Tom", 9},
    //      new Fixture{show, 1, 4, "Dick"},
    //      new Fixture{show, 1, 5, "Harry"}
    // };

    // qDebug() << "----------------------------------- ";
    // for (const auto &fixture : fixtures) {
    //     qDebug() << "Fixture" << fixture->id()
    //              << "U" << fixture->universe()
    //              << "dmx" << fixture->channel()
    //              << fixture->name();
    // }

    // // Create a QList of Fixture Groups
    // QList<FixtureGroup*> fixtureGroups = {
    //     new FixtureGroup{show,"Basil"},
    //     new FixtureGroup{show,"Sybil"},
    //     new FixtureGroup{show,"Polly"}
    // };

    // qDebug() << "----------------------------------- ";
    // for (const auto &fixtureGroup : fixtureGroups) {
    //     qDebug() << "FixtureGroup" << fixtureGroup->id() << fixtureGroup->name();
    // }

    qDebug() << "----------------------------------- ";
    // Put fixtures in the groups
    QPointer<FixtureGroup> fg = new FixtureGroup{show, "my fixture group"};
    QPointer<Fixture> f = new Fixture{show, 0, 0, "my fixture"};
    // qDebug() << "Fixture" << f->id() << "U" << f->universe() << "dmx" << f->channel() << f->name();
    // qDebug() << "FixtureGroup" << fg->id() << fg->name();

    QPointer<FixtureGroupItem> fgi = new FixtureGroupItem(fg, f);
    qDebug() << "FGI FG:" << fgi->fixtureGroupName()
             << "F: " << fgi->fixtureName();

    // QPointer<FixtureGroupItem> fgi2 = new FixtureGroupItem(
    //     fixtureGroups[1],
    //     fixtures[1]
    //     );
    // qDebug() << "FGI2 FG:" << fgi2->fixtureGroupName()
    //          << "F: " << fgi2->fixtureName();

    qDebug() << "----------------------------------- ";

    // // ask user to select a .hff file
    // QString fileName = QFileDialog::getOpenFileName(
    //     nullptr,                            // parent widget for dialog box
    //     ("Open Footlight Show"),            // prompt
    //     QDir::homePath(),                   // starting directory
    //     ("Footlight Files (*.json *.hff)")  // filter
    // );
    // qDebug() << "---" << typeid(fileName).name() << "---";
    // qDebug() << "---" << fileName << "---";

    // ShowWindow sw;
    // sw.show();

    NewOrOpenWindow newOrOpenWindow;
    newOrOpenWindow.show();

    return a.exec();
}
