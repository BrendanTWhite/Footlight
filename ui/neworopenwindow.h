#ifndef NEWOROPENWINDOW_H
#define NEWOROPENWINDOW_H

#include <QMainWindow>

namespace Ui {
class NewOrOpenWindow;
}

class NewOrOpenWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewOrOpenWindow(QWidget *parent = nullptr);
    ~NewOrOpenWindow();

private:
    Ui::NewOrOpenWindow *ui;
};

#endif // NEWOROPENWINDOW_H
