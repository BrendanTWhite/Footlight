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
    QCoreApplication::instance()->quit();
}


void HomeWindow::on_newShowButton_clicked()
{
    QApplication::activeWindow()->hide();
    // TODO make this     getHomeWindow()->hide();
    ShowWindow::createNewShowWindow();
}


void HomeWindow::on_actionNew_Show_triggered()
{
    QApplication::activeWindow()->hide();
    // TODO make this     getHomeWindow()->hide();
    ShowWindow::createNewShowWindow();
}

