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

    Fixture f = Fixture{1,2,"Fred"};

    qDebug() << "Fixture" << f.name()
             << "is in Universe" << f.universe()
             << "at Channel" << f.channel()
             << "and has ID" << f.id();



    return a.exec();
}
