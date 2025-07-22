#include "mainwindow.h"

#include "fixture.h"

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
    MainWindow w;
    w.show();



    Fixture f1 = Fixture{1,1,"Fred"};
    Fixture f2 = Fixture{1,2,"George"};
    Fixture f3 = Fixture{1,3,"Tom"};
    Fixture f4 = Fixture{1,4,"Dick"};
    Fixture f5 = Fixture{1,5,"Harry"};

    qDebug() << "Fixture" << f1.name()
             << "is in Universe" << f1.universe()
             << "at Channel" << f1.channel()
             << "and has ID" << f1.id();

    qDebug() << "Fixture" << f5.name()
             << "is in Universe" << f5.universe()
             << "at Channel" << f5.channel()
             << "and has ID" << f5.id();



    return a.exec();
}
