#include "classphonebook.h"

Phonebook::Phonebook(){}

/*Adds new Contact to Phonebook*/
void Phonebook::addContact(const string& firstName, const string& lastName, const string& phoneNumber, const string& nickname, const string& email) {
    if (phoneIndexMap_.find(phoneNumber) != phoneIndexMap_.end()) {
        qDebug()  << "There is another contact in your phonebook with the same number." << endl;
        return;
    }
    //Add a new contact at the end of vector
    Phonebook::contacts_.push_back(Contact(firstName, lastName, phoneNumber, nickname, email));
    //Add new contacts index to the map
    phoneIndexMap_[phoneNumber] = contacts_.size();
    //
    qDebug() << "Added to phonebook: " << contacts_.size() << ", " << firstName << " " << lastName << ", " << phoneNumber << ", " << nickname << endl;
}

/*Lists all Contacts or searchs for specific Contact depending on selected mode (all or index)*/
void Phonebook::searchContacts(const string& mode, const string& criteria) {
    if (mode == "all") {
        cout << "Index, First Name, Last Name, Phone Number, Nickname, Bookmarked" << endl;
        for (size_t i = 0; i < contacts_.size(); ++i) {
            qDebug()  << i + 1 << ", " << contacts_[i].firstName_ << " " << contacts_[i].lastName_ << ", " << contacts_[i].phoneNumber_ << ", " << contacts_[i].nickname_ << ", " << (contacts_[i].bookmarked_ ? "true" : "false") << endl;
        }
    }
    else if (mode == "index") {
        istringstream iss(criteria);
        int index;
        if (iss >> index && index >= 1 && index <= int(contacts_.size())) {
            index -= 1; // Convert to 0-based index
            qDebug()  << "Index, First Name, Last Name, Phone Number, Nickname, Bookmarked" << endl;
            qDebug()  << index + 1 << ", " << contacts_[index].firstName_ << " " << contacts_[index].lastName_ << ", " << contacts_[index].phoneNumber_ << ", " << contacts_[index].nickname_ << ", " << (contacts_[index].bookmarked_ ? "true" : "false") << endl;
        }
        else {
            qDebug()  << "Invalid index." << endl;
        }
    }
    else {
        qDebug()  << "Invalid search mode." << endl;
    }
}

/*Removes Contact depending on identifier (index or phone#)*/
void Phonebook::removeContact(const string& identifier, const string& value) {
    if (identifier == "index") {
        istringstream iss(value);
        int index;
        if (iss >> index && index >= 1 && index <= int(contacts_.size())) {
            index -= 1; // Convert to 0-based index
            string name = contacts_[index].firstName_ + " " + contacts_[index].lastName_;
            contacts_.erase(contacts_.begin() + index); // Delete Selected Contact (index) from Vector
            updatePhoneIndexMap(); // Update indexing in Phonebook
            qDebug()  << "Contact with the index " << index + 1 << " (" << name << ") has been removed." << endl;
        }
        else {
            qDebug()  << "No contact found with the given index." << endl;
        }
    }
    else if (identifier == "phone number") {
        if (phoneIndexMap_.find(value) != phoneIndexMap_.end()) {
            size_t index = phoneIndexMap_[value];
            string name = contacts_[index - 1].firstName_ + " " + contacts_[index - 1].lastName_;
            contacts_.erase(contacts_.begin() + index - 1); // Delete Selected Contact (index) from Vector
            updatePhoneIndexMap(); // Update indexing in Phonebook
            qDebug()  << "Contact with the phone number " << value << " (" << name << ") has been removed." << endl;
        }
        else {
            qDebug()  << "No contact found with the given phone number." << endl;
        }
    }
    else {
        qDebug()  << "Invalid identifier." << endl;
    }
}

/* Bookmark of a Contact is toggled depending on the passed identifier (phone# or index)*/
void Phonebook::bookmarkContact(const string& identifier, const string& value) {
    if (identifier == "index") {
        istringstream iss(value);
        int index;
        if (iss >> index && index >= 1 && index <= int(contacts_.size())) {
            index -= 1; // Convert to 0-based index
            contacts_[index].bookmarked_ = !contacts_[index].bookmarked_; // toggle bookmark
            string name = contacts_[index].firstName_ + " " + contacts_[index].lastName_;
            qDebug()  << "Contact with the index " << index + 1 << " (" << name << ") has been " << (contacts_[index].bookmarked_ ? "bookmarked." : "unbookmarked.") << endl;
        }
        else {
            qDebug()  << "Invalid index." << endl;
        }
    }
    else {
        qDebug()  << "Invalid identifier." << endl;
    }
}

/* Sets new index in Phonebook if a Contact is removed/stored.*/
void Phonebook::updatePhoneIndexMap() {
    phoneIndexMap_.clear();
    for (size_t i = 0; i < contacts_.size(); ++i) {
        phoneIndexMap_[contacts_[i].phoneNumber_] = i + 1;
    }
}
