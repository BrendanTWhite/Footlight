#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QItemSelectionModel>
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

    FixtureModel* model_ptr_in_window; // why both
    QList<Fixture> list_in_window;     // of these?


};
#endif // MAINWINDOW_H
