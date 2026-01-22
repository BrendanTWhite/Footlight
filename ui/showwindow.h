#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelectionModel>
#include <QPointer>

#include "fixturemodel.h"
#include "../models/show.h"

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

    QPointer<Show> getShow() const;

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
    ShowWindow(QPointer<Show> show);

    Ui::ShowWindow *ui;
    QPointer<Show> m_show;
    FixtureModel m_fixture_model;
};
#endif // MAINWINDOW_H
