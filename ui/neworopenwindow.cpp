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


void NewOrOpenWindow::on_newShowButton_clicked()
{
    QApplication::activeWindow()->hide();
    ShowWindow::createNewShowWindow();
}


void NewOrOpenWindow::on_actionNew_Show_triggered()
{
    QApplication::activeWindow()->hide();
    ShowWindow::createNewShowWindow();
}

