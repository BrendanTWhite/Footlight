#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::on_quitButton_clicked()
{
    QCoreApplication::quit();
}


void HomeWindow::on_newShowButton_clicked()
{
    this->hide();
    ShowWindow::createNewShowWindow();
}


void HomeWindow::on_actionNew_Show_triggered()
{
    this->hide();
    ShowWindow::createNewShowWindow();
}


void HomeWindow::on_openOtherButton_clicked()
{
    ShowWindow::openExistingShow();
}


void HomeWindow::on_actionOpen_Show_triggered()
{
    ShowWindow::openExistingShow();
}

