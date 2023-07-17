#include "graphicalphonebook.h"
#include "ui_graphicalphonebook.h"


GraphicalPhonebook::GraphicalPhonebook(QWidget *parent):QDialog(parent),ui(new Ui::GraphicalPhonebook)
{
    ui->setupUi(this);
    // Connectors
    /* A connector is not needed, if a slot is created through the GUI designer - Signal, Slots and Reciever are connected automaticly by "Right click"->"Go to Slot"->...
     * For instance: If the following connectors are implemented anyway, the slot / memeber functions will be calles twice when the sender is triggered.
     * connect(ui->addPushButton, &QPushButton::clicked, this, &GraphicalPhonebook::on_addPushButton_clicked);
     * connect(ui->exportPushButton, &QPushButton:clicked, this, &GraphicalPhonebook::on_exportPushButton_clicked);
     * connect(ui->contactsTableWidget, &QTableWidget::itemChanged, ui->exportPushButton, &QPushButton::setEnabled);
     * ....
    */
    // Configuration on ui elements
    ui->contactsTableWidget->setColumnWidth(0,25); // id
    ui->contactsTableWidget->setColumnWidth(1,80); // firstname
    ui->contactsTableWidget->setColumnWidth(2,125); // lastname
    ui->contactsTableWidget->setColumnWidth(3,125); // phonenumber
    ui->contactsTableWidget->setColumnWidth(4,125); // email
    ui->contactsTableWidget->setColumnWidth(5,80); // nickname
    ui->contactsTableWidget->setColumnWidth(6,25); // bookmark
    ui->contactsTableWidget->verticalHeader()->setVisible(false); // hide rowcount
    ui->contactsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->firstnameLineEdit->setText("Max");
    ui->lastnameLineEdit->setText("Mustermann");
    ui->phonenumberLineEdit->setText("+49 123 4567890");
    ui->emailaddressLineEdit->setText("max@mustermann.eu");
    ui->nicknameLineEdit->setText("Maxi");
}

GraphicalPhonebook::~GraphicalPhonebook()
{
    delete ui;
}

// functions

void GraphicalPhonebook::updateContactTable(vector<vector<string>> data)
{
    //enable/disable buttons accordingly to user input
    if(data.empty())
    {
        ui->contactsTableWidget->clearContents();
        ui->exportPushButton->setEnabled(false);
        ui->bookmarkPushButton->setEnabled(false);
        ui->removePushButton->setEnabled(false);
        ui->editPushButton->setEnabled(false);
        return;
    }
    else if(data.size()==1 && (selectQString_.toStdString() !=""))
    {
        ui->bookmarkPushButton->setEnabled(true);
        ui->removePushButton->setEnabled(true);
        ui->editPushButton->setEnabled(true);
    }
    else
    {
        ui->bookmarkPushButton->setEnabled(false);
        ui->removePushButton->setEnabled(false);
        ui->editPushButton->setEnabled(false);
    }

    // load phonebook in table
    for (unsigned long row=0; row<data.size(); ++row)
    {
        // create item (each cell in table consists a item)
        QTableWidgetItem *item;

        // set number of rows in table
        ui->contactsTableWidget->setRowCount(row+1);

        // loop through data and fill table with content (Assuming all inner vectors have the same number of columns.)
        for (unsigned long col=0; col<data[0].size()-1; ++col)
        {
            // create new item (contact)
            item = new QTableWidgetItem(QString::fromStdString(data[row][col]));

            // put item into table cell
            ui->contactsTableWidget->setItem(row, col, item);

            // enable export button
            ui->exportPushButton->setEnabled(true);

            // checkboxes for bookmarked contacts
            if(col==data[0].size()-2)
            {
                // Declare and initialize the checkbox
                QCheckBox *checkBox = new QCheckBox();
                // Set Checkbox readonly, but not grayed-out
                checkBox->setAttribute(Qt::WA_TransparentForMouseEvents);
                checkBox->setFocusPolicy(Qt::NoFocus);
                // set Checkbox if contact is bookmarked
                if(data[row][col+1] == "true"){
                    checkBox->setChecked(true);
                } else {
                    checkBox->setChecked(false);
                }
                // put in table
                ui->contactsTableWidget->setCellWidget(row,col+1, checkBox);
                // deallocate checkboxes
                checkBox = nullptr;
                delete checkBox;
            }
        }

        // deallocate item
        item = nullptr;
        delete item;
    }
}

void GraphicalPhonebook::exportContacts(QTableWidget* contactTable, const QString& filename)
{
    // Create a new file
    QFile file(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    // loop through contact tables and save in file.
    int rows = contactTable->rowCount();
    int cols = contactTable->columnCount();
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            QTableWidgetItem* item = contactTable->item(row, col);
            if (item)
                out << item->text();
            if (col < cols - 1)
                out << ';';
        }
        out << '\n';
    }

    // Optional, as QFile destructor will already do it.
    file.close();

    // user feedback where the file is saved.
    QMessageBox exported;
    exported.setText("Phonebook saved to: "+filename);
    exported.setStandardButtons(QMessageBox::Ok);
    exported.exec();
}

// Private Slots

void GraphicalPhonebook::on_addPushButton_clicked()
{
    // get user input from Line Edit & save in memeber variables
    firstnameQString_    =  ui->firstnameLineEdit->text();
    lastnameQString_     =  ui->lastnameLineEdit->text();
    phonenumberQString_  =  ui->phonenumberLineEdit->text();
    eMailQString_        =  ui->emailaddressLineEdit->text();
    nicknameQString_     =  ui->nicknameLineEdit->text();

    // convert memeber variables to strings
    string firstname     = firstnameQString_.toStdString();
    string lastname      = lastnameQString_.toStdString();
    string phonenumber   = phonenumberQString_.toStdString();
    string email         = eMailQString_.toStdString();
    string nickname      = nicknameQString_.toStdString();

    // pass new contact to phonebook's add methode
    bool successfull = phonebook.addContact(firstname,lastname,phonenumber,nickname,email);

    // give user feedback if user was added
    if (!successfull)
    {
        QMessageBox noContactAdded;
        noContactAdded.setText("There is already a contact with the same phone number.");
        noContactAdded.setStandardButtons(QMessageBox::Ok);
        noContactAdded.exec();
    }
    else if(successfull)
    {
        QMessageBox Contactadded;
        Contactadded.setText("Contact added to phonebook.");
        Contactadded.setStandardButtons(QMessageBox::Ok);
        Contactadded.exec();
    }

    // get all contacts from phonebook
    vector<vector<string>> data = phonebook.searchContacts("all","");

    // update contacts in table
    this->updateContactTable(data);
}

void GraphicalPhonebook::on_exportPushButton_clicked()
{
    // get os desktop path
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

    // append filename to path
    QString filename = desktopPath + "/phonebook_export.csv";

    // call slot that exports the current phonebook
    this->exportContacts(ui->contactsTableWidget, filename);
}

void GraphicalPhonebook::on_bookmarkPushButton_clicked()
{
    // get user input
    string select = selectQString_.toStdString();
    string mode = "index";
    bool successfull = phonebook.bookmarkContact(mode,select);

    // create message
    if (!successfull)
    {
        QMessageBox noContactbookmarked;
        noContactbookmarked.setText("There is no contact with the given id.");
        noContactbookmarked.setStandardButtons(QMessageBox::Ok);
        noContactbookmarked.exec();
    }
    else if(successfull)
    {
        QMessageBox Contactbookmarked;
        Contactbookmarked.setText("Bookmark on Contact toggeled.");
        Contactbookmarked.setStandardButtons(QMessageBox::Ok);
        Contactbookmarked.exec();
    }

    // get all contacts from phonebook
    vector<vector<string>> data = phonebook.searchContacts("all","");

    // update contacts in table
    this->updateContactTable(data);
}

void GraphicalPhonebook::on_selectContactLineEdit_textChanged(const QString &arg1)
{
    // get user input
    selectQString_ =  ui->selectContactLineEdit->text();
    string select = selectQString_.toStdString();

    // search by index as "default"
    string mode = "index";

    // if no user input was provided, the whole phonebook should be displayed.
    if(select == "")
    {
        mode="all";
    }

    // get contacts
    vector<vector<string>> data = phonebook.searchContacts(mode,select);

    // update table
    this->updateContactTable(data);
}

void GraphicalPhonebook::on_removePushButton_clicked()
{
    // get user input
    string select = selectQString_.toStdString();
    string mode = "index";

    // remove contact from phonebook
    bool successfull = phonebook.removeContact(mode,select);

    // create user message
    if (!successfull)
    {
        QMessageBox noContactremoved;
        noContactremoved.setText("Contact could not be removed.");
        noContactremoved.setStandardButtons(QMessageBox::Ok);
        noContactremoved.exec();
    }
    else if(successfull)
    {
        QMessageBox Contactremoved;
        Contactremoved.setText("Contact removed.");
        Contactremoved.setStandardButtons(QMessageBox::Ok);
        Contactremoved.exec();
    }

    // get all contacts from phonebook
    vector<vector<string>> data = phonebook.searchContacts("all","");

    // update contacts in table
    this->updateContactTable(data);
}

void GraphicalPhonebook::on_editPushButton_clicked()
{
    // get user input
    string select = selectQString_.toStdString();   // ID
    string mode = "index";                          // ID or Phonenumber

    // get & save contact from phonebook
    vector<vector<string>> data = phonebook.searchContacts(mode,select);
    firstnameQString_   = QString::fromStdString(data[0][1]);
    lastnameQString_    = QString::fromStdString(data[0][2]);
    phonenumberQString_ = QString::fromStdString(data[0][3]);
    eMailQString_       = QString::fromStdString(data[0][4]);
    nicknameQString_    = QString::fromStdString(data[0][5]);

    // put saved contact information into line edit
    ui->firstnameLineEdit->setText(firstnameQString_);
    ui->lastnameLineEdit->setText(lastnameQString_);
    ui->phonenumberLineEdit->setText(phonenumberQString_);
    ui->emailaddressLineEdit->setText(eMailQString_);
    ui->nicknameLineEdit->setText(nicknameQString_);

    // delete the selected contact
    bool successfull = phonebook.removeContact(mode,select);

    // create user notification
    if (!successfull)
    {
        QMessageBox NoContactEdited;
        NoContactEdited.setText("Contact could not be edited.");
        NoContactEdited.setStandardButtons(QMessageBox::Ok);
        NoContactEdited.exec();
    }
    else if(successfull)
    {
        QMessageBox Contactedited;
        Contactedited.setText("Contact loaded to add section.\n If you are done editing press the add button to save the contact back to your phonebook.");
        Contactedited.setStandardButtons(QMessageBox::Ok);
        Contactedited.exec();
    }

    // get all contacts from phonebook
    data = phonebook.searchContacts("all","");

    // update contacts in table
    this->updateContactTable(data);
}

