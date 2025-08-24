#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelectionModel>

#include "fixturemodel.h"


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
    ~ShowWindow();

private slots:
    void onSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected);

    void on_actionNew_triggered();

    void on_actionClose_triggered();

    void on_fixturesAddButton_clicked();

    void on_groupsAddButton_clicked();

    void on_scenesAddButton_clicked();

    void on_cuesAddButton_clicked();

private:
    ShowWindow(QWidget *parent = nullptr);

    Ui::ShowWindow *ui;
    FixtureModel fixtureModel;
};
#endif // MAINWINDOW_H
