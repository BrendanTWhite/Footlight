#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QItemSelectionModel>
#include <QSqlDatabase>

// #include <QPointer>

// #include "fixturemodel.h"
#include "../models/show.h"

class FixtureModel; // forward declaration, to allow ptrs & refs
class Fixture; // forward declaration, to allow ptrs & refs


QT_BEGIN_NAMESPACE
namespace Ui {
    class ShowWindow;
}
QT_END_NAMESPACE

class ShowWindow : public QMainWindow
{
    Q_OBJECT

public:
    static void createNewShowWindow(bool showImmediately = true);
    static void openExistingShow(QString filePath = QString());

    ~ShowWindow();

    // QList<Fixture> getFixtures() const; // not used
    // void setFixtures(const QList<Fixture> &newFixtures); // not used


private slots:
    void onSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected);

    void on_actionNew_triggered();

    void on_actionClose_triggered();

    void on_fixturesAddButton_clicked();

    void on_groupsAddButton_clicked();

    void on_statesAddButton_clicked();

    void on_cuesAddButton_clicked();

    void on_actionOpen_triggered();

private:
    ShowWindow(
        // QPointer<Show> show
               );

    Ui::ShowWindow* ui;
    // QPointer<Show> m_show;
    // FixtureModel m_fixture_model;

    QSqlDatabase db;
    QString connection_name;
    // A database connection must only be used from within
    // the thread that it's associated with, which is generally
    // the thread that created it.
    // Moving a connection into another thread can be done with
    // QSqlDatabase::moveToThread().
    // See https://doc.qt.io/qt-6/threads-modules.html#threads-and-the-sql-module
    //
    // to re-use the existing connection
    // (in the same thread)
    // just use the existing db member variable.
    //
    // To get a new connection to this db
    // (in any thread)
    // use https://doc.qt.io/qt-6/qsqldatabase.html#database
    // with this connection_name

    FixtureModel* model_ptr_in_window; // why both
    QList<Fixture> list_in_window;     // of these?


};
#endif // MAINWINDOW_H
