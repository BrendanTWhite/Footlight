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
