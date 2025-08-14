#include "showwindow.h"
#include "ui_showwindow.h"

ShowWindow::ShowWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ShowWindow)
{
    ui->setupUi(this);
}

ShowWindow::~ShowWindow()
{
    delete ui;
}

 void ShowWindow::createNewShowWindow() {
    ShowWindow *newShowWindow = new ShowWindow();
    newShowWindow->setAttribute(Qt::WA_DeleteOnClose);
    newShowWindow->show();
}


void ShowWindow::on_actionNew_triggered()
{
    createNewShowWindow();
}


void ShowWindow::on_actionClose_triggered()
{
    this->close();
}


void ShowWindow::on_fixturesAddButton_clicked()
{
    this->window()->setWindowModified(true);
}


void ShowWindow::on_groupsAddButton_clicked()
{
    this->window()->setWindowModified(true);
}


void ShowWindow::on_scenesAddButton_clicked()
{
    this->window()->setWindowModified(true);
}


void ShowWindow::on_cuesAddButton_clicked()
{
    this->window()->setWindowModified(true);
}

