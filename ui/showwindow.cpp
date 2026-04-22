#include "showwindow.h"
#include "ui_showwindow.h"

#include "fixturemodel.h"
#include "../models/fixture.h"

#include <QFileDialog>
#include <QtDebug>
#include <QDir>
#include <QMessageBox>
#include <QInputDialog>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QUuid>

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



    // database playground
    //     from https://cengizhanvarli.medium.com/qt-sql-operations-b9031dfc1a20

    connection_name = QUuid::createUuid().toString(QUuid::WithoutBraces);

    // https://doc.qt.io/qt-6/qsqldatabase.html#addDatabase
    // This sets the connectionName. The database connection is referred to by connectionName.
    // If connectionName is not specified, the new connection becomes the default connection
    // for the application, and subsequent calls to database() without the connection name argument
    // will return the default connection.
    // If a connectionName is provided here, use database(connectionName) to retrieve the connection.
    db = QSqlDatabase::addDatabase("QSQLITE", connection_name);

    // https://doc.qt.io/qt-6/qsqldatabase.html#setDatabaseName
    // The database name is usually the filename on disk.
    // But if the database name is set to an empty string,
    // it creates a temporary database, which disappears on close().

    db.setDatabaseName(QString(""));

    if (!db.open()) {
        qDebug() << "Cannot open database:" << db.lastError().text();
        // return -1;
    }
    qDebug() << "Database connected - " + db.connectionName();

    QSqlQuery query(db);


    if (!query.exec(
            "    create table if not exists fixture_type ("
            "        id integer,"
            "        model varchar,"
            "        manufacturer varchar,"
            "        primary key (id)"
            "        );"

        )) {
        qDebug() << "Error:" << query.lastError().text();
    }

    if (!query.exec(

            "insert into fixture_type "
            "	(id, model, manufacturer) "
            "values "
            "	(1, 'ParCan', 'Acme'),"
            "	(2, 'Profile', 'Acme'),"
            "	(3, 'Follow Spot', 'Acme')"

            )) {
        qDebug() << "Error:" << query.lastError().text();
    }

    if (!query.exec(


            "    create table if not exists fixture ("
            "        id integer,"
            "        fixture_type_id integer not null,"

            "        name varchar not null, "
            "        universe varchar, "
            "        dmx_channel varchar, "

            "        foreign key (fixture_type_id) references fixture_type(id),"
            "        primary key (id)"
            "        );"

        )) {
        qDebug() << "Error:" << query.lastError().text();
    }

    if (!query.exec(

            "insert into fixture "
            "	(id, name, fixture_type_id, universe, dmx_channel) "
            "values "
            "	(1, 'OP Wash', 1, 1, 12),"
            "	(2, 'C Wash',  1, 1, 23),"
            "	(3, 'P Wash',  1, 1, 34),"
            "	(4, 'OP Spot', 3, 1, 45),"
            "	(5, 'P Spot',  3, 1, 56)"

        )) {
        qDebug() << "Error:" << query.lastError().text();
    }

}

// QPointer<Show> ShowWindow::getShow() const
// {
//     return this->m_show;
// }

ShowWindow::~ShowWindow()
{
    qDebug() << "Closing connection - " + db.connectionName();
    db.close();
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

