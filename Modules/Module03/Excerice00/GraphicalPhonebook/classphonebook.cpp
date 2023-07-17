#include "classphonebook.h"
// Default Constructor
Phonebook::Phonebook(){}
// Deconstructor
Phonebook::~Phonebook(){}
/*Adds new Contact to Phonebook*/
bool Phonebook::addContact(const string& firstName, const string& lastName, const string& phoneNumber, const string& nickname, const string& email) {
    if (phoneIndexMap_.find(phoneNumber) != phoneIndexMap_.end()) {
        qDebug()  << "There is already a contact with the same phone number";
        return false;
    }
    //Add a new contact at the end of vector
    Phonebook::contacts_.push_back(Contact(firstName, lastName, phoneNumber, nickname, email));
    //Add new contacts index to the map
    phoneIndexMap_[phoneNumber] = contacts_.size();
    //
    qDebug() <<  "Added to phonebook.";
    return true;
}


/*Lists all Contacts or searchs for specific contact depending on selected mode (all or index)j
 * return: empty: invalid index, empty phonebook, 2D-String-Array, if not.
*/
vector<vector<string>> Phonebook::searchContacts(const string& mode, const string& criteria) const{
    vector<vector<string>> contactlist; // 2D-String-Array contatlist
    if (mode == "all")
    {
        int rows = contacts_.size(); // length of contact list
        for (int i = 0; i < rows; i++)
        {
            // create new contact string and append to contactlist
            vector<string> contact ={
                to_string(i + 1),
                contacts_[i].firstName_,
                contacts_[i].lastName_,
                contacts_[i].phoneNumber_,
                contacts_[i].email_ ,
                contacts_[i].nickname_,
                (contacts_[i].bookmarked_ ? "true" : "false")
            };
            contactlist.push_back(contact);
        }
    }
    else if (mode == "index")
    {
        istringstream iss(criteria);
        int index;
        if (iss >> index && index >= 1 && index <= int(contacts_.size())) {
            index -= 1; // Convert to 0-based index
            vector<string> contact = {
                to_string(index + 1),
                contacts_[index].firstName_,
                contacts_[index].lastName_,
                contacts_[index].phoneNumber_,
                contacts_[index].email_ ,
                contacts_[index].nickname_,
                (contacts_[index].bookmarked_ ? "true" : "false")
            };
            contactlist.push_back(contact);
        }
        else {
            qDebug()  << "Invalid index.";
        }
    }
    else {
        qDebug()  << "Invalid search mode.";
    }

    // print results to qDebug
    for (const auto& row : contactlist) {
        QString rowString;
        for (const auto& element : row) {
            rowString += QString::fromStdString(element) + " ";
        }
        qDebug() << rowString;
    }

    // return of contactlist
    return contactlist;
}

/*Removes Contact depending on identifier (index or phone#)*/
bool Phonebook::removeContact(const string& identifier, const string& value) {
    bool ret = false;
    if (identifier == "index") {
        istringstream iss(value);
        int index;
        if (iss >> index && index >= 1 && index <= int(contacts_.size())) {
            index -= 1; // Convert to 0-based index
            //string name = contacts_[index].firstName_ + " " + contacts_[index].lastName_;
            contacts_.erase(contacts_.begin() + index); // Delete Selected Contact (index) from Vector
            updatePhoneIndexMap(); // Update indexing in Phonebook
            qDebug()  << "Contact with the index " << index + 1 << " has been removed.";
            ret = true;
        }
        else {
            qDebug()  << "No contact found with the given index.";
            ret = false;
        }
    }
    else if (identifier == "phone number") {
        if (phoneIndexMap_.find(value) != phoneIndexMap_.end()) {
            size_t index = phoneIndexMap_[value];
            //string name = contacts_[index - 1].firstName_ + " " + contacts_[index - 1].lastName_;
            contacts_.erase(contacts_.begin() + index - 1); // Delete Selected Contact (index) from Vector
            updatePhoneIndexMap(); // Update indexing in Phonebook
            qDebug()  << "Contact with the phone number " << QString::fromStdString(value) << "has been removed.";
            ret = true;
        }
        else {
            qDebug()  << "No contact found with the given phone number.";
            ret = false;
        }
    }
    else {
        qDebug()  << "Invalid identifier.";
        ret = false;
    }
    return ret;
}


/* Bookmark of a Contact is toggled depending on the passed identifier (phone# or index)*/
bool Phonebook::bookmarkContact(const string& identifier, const string& value) {
    bool ret = false;
    if (identifier == "index") {
        istringstream iss(value);
        int index;
        if (iss >> index && index >= 1 && index <= int(contacts_.size())) {
            index -= 1; // Convert to 0-based index
            contacts_[index].bookmarked_ = !contacts_[index].bookmarked_; // toggle bookmark
            qDebug()  << "Contact with the index " << index + 1 << QString::fromStdString((contacts_[index].bookmarked_ ? "bookmarked." : "unbookmarked."));
            ret = true;
        }
        else {
            qDebug()  << "Invalid index.";
            ret = false;
        }
    }
    else{
        qDebug()  << "Invalid identifier.";
        ret = false;
    }
    return ret;
}

/* Sets new index in Phonebook if a Contact is removed/stored.*/
void Phonebook::updatePhoneIndexMap() {
    phoneIndexMap_.clear();
    for (size_t i = 0; i < contacts_.size(); ++i) {
        phoneIndexMap_[contacts_[i].phoneNumber_] = i + 1;
    }
}
