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
    QMainWindow::statusBar()->showMessage(tr("fixtures AddButton clicked"), 2000);
    this->window()->setWindowModified(true);
}


void ShowWindow::on_groupsAddButton_clicked()
{
    QMainWindow::statusBar()->showMessage(tr("groups AddButton clicked"), 2000);
    this->window()->setWindowModified(true);
}


void ShowWindow::on_scenesAddButton_clicked()
{
    QMainWindow::statusBar()->showMessage(tr("scenes AddButton clicked"), 2000);
    this->window()->setWindowModified(true);
}


void ShowWindow::on_cuesAddButton_clicked()
{
    QMainWindow::statusBar()->showMessage(tr("cues AddButton clicked"), 2000);
    this->window()->setWindowModified(true);
}

