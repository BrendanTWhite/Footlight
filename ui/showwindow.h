#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ShowWindow;
}
QT_END_NAMESPACE

class ShowWindow : public QMainWindow
{
    Q_OBJECT

public:
    ShowWindow(QWidget *parent = nullptr);
    static void createNewShowWindow();
    ~ShowWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionClose_triggered();

    void on_fixturesAddButton_clicked();

    void on_groupsAddButton_clicked();

    void on_scenesAddButton_clicked();

    void on_cuesAddButton_clicked();

private:
    Ui::ShowWindow *ui;
};
#endif // MAINWINDOW_H
