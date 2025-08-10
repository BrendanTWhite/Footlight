#include "neworopenwindow.h"
#include "ui_neworopenwindow.h"

NewOrOpenWindow::NewOrOpenWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NewOrOpenWindow)
{
    ui->setupUi(this);
}

NewOrOpenWindow::~NewOrOpenWindow()
{
    delete ui;
}

void NewOrOpenWindow::on_quitButton_clicked()
{
    QCoreApplication::instance()->quit();
}

