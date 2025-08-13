#ifndef NEWOROPENWINDOW_H
#define NEWOROPENWINDOW_H

#include <QMainWindow>
#include "showwindow.h"

namespace Ui {
class NewOrOpenWindow;
}

class NewOrOpenWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewOrOpenWindow(QWidget *parent = nullptr);
    ~NewOrOpenWindow();

private slots:
    void on_quitButton_clicked();

    void on_newShowButton_clicked();

    void on_actionNew_Show_triggered();

private:
    Ui::NewOrOpenWindow *ui;
};

#endif // NEWOROPENWINDOW_H
