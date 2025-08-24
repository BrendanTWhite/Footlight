#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include "showwindow.h"

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

private slots:
    void on_quitButton_clicked();

    void on_newShowButton_clicked();

    void on_actionNew_Show_triggered();

    void on_openOtherButton_clicked();

    void on_actionOpen_Show_triggered();

private:
    Ui::HomeWindow *ui;
};

#endif // HOMEWINDOW_H
