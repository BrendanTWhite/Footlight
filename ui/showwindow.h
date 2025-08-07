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
    ~ShowWindow();

private:
    Ui::ShowWindow *ui;
};
#endif // MAINWINDOW_H
