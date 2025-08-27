#include <QFileDialog>
#include <QtDebug>
#include <QDir>

#include "showwindow.h"
#include "ui_showwindow.h"

ShowWindow::ShowWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowWindow),
    m_fixture_model(this)
{
    ui->setupUi(this);

    ui->fixturesView->setModel(&m_fixture_model);

    m_show = new Show("asdf");

    QItemSelectionModel* selectionModel = ui->fixturesView->selectionModel();
    connect(selectionModel, &QItemSelectionModel::selectionChanged,
            this, &ShowWindow::onSelectionChanged);
}

ShowWindow::~ShowWindow()
{
    delete ui;
}


void ShowWindow::onSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
    Q_UNUSED(deselected)

    QModelIndexList list = selected.indexes();
    const QModelIndex& index = list.first();

    // QString countryName = index.data(Qt::DisplayRole).toString();
    // ui->countryNameLabel->setText(countryName);

    // QString countryCapital = index.data(CountryModel::CapitalRole).toString();
    // ui->countryCapitalLabel->setText(countryCapital);

}

void ShowWindow::openExistingShow(QString filePath) {

    // First, get file path (if not already supplied)
    if (filePath == "") {
        filePath = QFileDialog::getOpenFileName(
            nullptr,
            tr("Open HF Footlights file"),
            QDir::homePath(),
            tr("HF Footlights files") + " (*.hff *.json)"
            );

    }
    qDebug() << "Attempting to open: " << filePath;

    // Then, get QFile from this file path
    QFile file = QFile(filePath);

    // Then, attempt to load the contents of the file in to this->show()
    // TODO - implement this



}

void ShowWindow::createNewShowWindow(bool showImmediately) {
    ShowWindow *newShowWindow = new ShowWindow();
    newShowWindow->setAttribute(Qt::WA_DeleteOnClose);

    if (showImmediately) {
        newShowWindow->show();
    }
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
    this->statusBar()->showMessage(tr("fixtures AddButton clicked"), 2000);
    this->window()->setWindowModified(true);
}


void ShowWindow::on_groupsAddButton_clicked()
{
    this->statusBar()->showMessage(tr("groups AddButton clicked"), 2000);
    this->window()->setWindowModified(true);
}


void ShowWindow::on_scenesAddButton_clicked()
{
    this->statusBar()->showMessage(tr("scenes AddButton clicked"), 2000);
    this->window()->setWindowModified(true);
}


void ShowWindow::on_cuesAddButton_clicked()
{
    this->statusBar()->showMessage(tr("cues AddButton clicked"), 2000);
    this->window()->setWindowModified(true);
}


void ShowWindow::on_actionOpen_triggered()
{
    openExistingShow();
}

