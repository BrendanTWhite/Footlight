#include "showwindow.h"
#include "ui_showwindow.h"

#include "fixturemodel.h"
#include "../models/fixture.h"

#include <QFileDialog>
#include <QtDebug>
#include <QDir>
#include <QMessageBox>
#include <QInputDialog>


ShowWindow::ShowWindow(
    // QPointer<Show> show
    ) :
    QMainWindow(nullptr),
    ui(new Ui::ShowWindow),
    model_ptr_in_window(new FixtureModel(this->list_in_window, this))
{
    // m_show = show;
    // m_show->setParent(this); // show's parent is showwindow

    ui->setupUi(this);
    ui->fixturesView->setModel(model_ptr_in_window);

    // QItemSelectionModel* selectionModel = ui->fixturesView->selectionModel();

    // connect(selectionModel, &QItemSelectionModel::selectionChanged,
    //         this, &ShowWindow::onSelectionChanged);

}

// QPointer<Show> ShowWindow::getShow() const
// {
//     return this->m_show;
// }

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

    // QPointer<Show> newShow = new Show(tr("New Show"));
    // QPointer<ShowWindow> newShowWindow = new ShowWindow();
    ShowWindow* newShowWindow = new ShowWindow();

    newShowWindow->setAttribute(Qt::WA_DeleteOnClose);
    // newShowWindow->setWindowTitle(newShow->name());
    newShowWindow->setWindowTitle("Batman Window");

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
    // this->getShow()->addNewFixture();
    this->window()->setWindowModified(true);

// Obvs, we need to get this from somewhere sensible
    QString name = "Potato";
    QString universe = "1";
    QString channel = "123";
// Obvs, once we've got it, we need to validate it before saving

    // If we got this far, then everything is good to go
    model_ptr_in_window->addFixture(name, universe,channel);
}



// void ContactWindow::removeContact() { // aka on_fixturesDeleteButton_clicked()
//     QModelIndex index = ui_ptr->contactTableView->currentIndex();
//     if (index.isValid()) {
//         model_ptr_in_window->removeContact(index.row());
//     } else {
//         QMessageBox::warning(this, "Warning", "Please select a contact to remove.");
//     }
// }


// void ContactWindow::editContact() { // aka on_fixturesEditButton_clicked()
//     QModelIndex index = ui_ptr->contactTableView->currentIndex();
//     if (index.isValid()) {

//         QString currentName = model_ptr_in_window->data(model_ptr_in_window->index(index.row(), 0)).toString();
//         QString currentNumber = model_ptr_in_window->data(model_ptr_in_window->index(index.row(), 1)).toString();


//         QString name = QInputDialog::getText(this, "Edit Contact", "Enter new contact name:", QLineEdit::Normal, currentName);
//         if (!name.isEmpty()) {
//             QString number = QInputDialog::getText(this, "Edit Contact", "Enter new contact number:", QLineEdit::Normal, currentNumber);
//             if (!number.isEmpty()) {

//                 model_ptr_in_window->setData(model_ptr_in_window->index(index.row(), 0), name);
//                 model_ptr_in_window->setData(model_ptr_in_window->index(index.row(), 1), number);
//             }
//         }
//     } else {
//         QMessageBox::warning(this, "Warning", "Please select a contact to edit.");
//     }







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

