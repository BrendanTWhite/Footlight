#include <QFileDialog>
#include <QtDebug>
#include <QDir>

#include "showwindow.h"
#include "ui_showwindow.h"

ShowWindow::ShowWindow(QPointer<Show> show) :
    QMainWindow(nullptr),
    ui(new Ui::ShowWindow),
    m_fixture_model(this)
{
    m_show = show;
    m_show->setParent(this); // show's parent is showwindow

    ui->setupUi(this);

    ui->fixturesView->setModel(&m_fixture_model);

    QItemSelectionModel* selectionModel = ui->fixturesView->selectionModel();
    connect(selectionModel, &QItemSelectionModel::selectionChanged,
            this, &ShowWindow::onSelectionChanged);
}

QPointer<Show> ShowWindow::getShow() const
{
    return this->m_show;
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

    QPointer<Show> newShow = new Show(tr("New Show"));
    QPointer<ShowWindow> newShowWindow = new ShowWindow(newShow);

    newShowWindow->setAttribute(Qt::WA_DeleteOnClose);
    newShowWindow->setWindowTitle(newShow->name());

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
    this->getShow()->addNewFixture();
    this->window()->setWindowModified(true);
}


void ShowWindow::on_groupsAddButton_clicked()
{
    this->statusBar()->showMessage(tr("groups AddButton clicked"), 2000);
    this->window()->setWindowModified(true);
}


void ShowWindow::on_statesAddButton_clicked()
{
    this->statusBar()->showMessage(tr("states AddButton clicked"), 2000);
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

