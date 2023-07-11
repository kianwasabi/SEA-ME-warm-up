#include "../include/phonebook.h"

// namespace Phonebook{

Phonebook::Phonebook(){};

/*Adds new Contact to Phonebook*/
void Phonebook::addContact(const string& firstName, const string& lastName, const string& phoneNumber, const string& nickname) {
        if (phoneIndexMap.find(phoneNumber) != phoneIndexMap.end()) {
            cout << "There is another contact in your phonebook with the same number." << endl;
            return;
        }

        Phonebook::contacts.push_back(Contact(firstName, lastName, phoneNumber, nickname));
        phoneIndexMap[phoneNumber] = contacts.size();

        cout << "Added to phonebook: " << contacts.size() << ", " << firstName << " " << lastName << ", " << phoneNumber << ", " << nickname << endl;
    }
/*Lists all Contacts or searchs for specific Contact depending on selected mode (all or index)*/
void Phonebook::searchContacts(const string& mode, const string& criteria) {
        if (mode == "all") {
            cout << "Index, First Name, Last Name, Phone Number, Nickname, Bookmarked" << endl;
            for (size_t i = 0; i < contacts.size(); ++i) {
                cout << i + 1 << ", " << contacts[i].firstName << " " << contacts[i].lastName << ", " << contacts[i].phoneNumber << ", " << contacts[i].nickname << ", " << (contacts[i].bookmarked ? "true" : "false") << endl;
            }
        }
        else if (mode == "index") {
            istringstream iss(criteria);
            int index;
            if (iss >> index && index >= 1 && index <= contacts.size()) {
                index -= 1; // Convert to 0-based index
                cout << "Index, First Name, Last Name, Phone Number, Nickname, Bookmarked" << endl;
                cout << index + 1 << ", " << contacts[index].firstName << " " << contacts[index].lastName << ", " << contacts[index].phoneNumber << ", " << contacts[index].nickname << ", " << (contacts[index].bookmarked ? "true" : "false") << endl;
            }
            else {
                cout << "Invalid index." << endl;
            }
        }
        else {
            cout << "Invalid search mode." << endl;
        }
    }
/*Removes Contact depending on identifier (index or phone#)*/
void Phonebook::removeContact(const string& identifier, const string& value) {
        if (identifier == "index") {
            istringstream iss(value);
            int index;
            if (iss >> index && index >= 1 && index <= contacts.size()) {
                index -= 1; // Convert to 0-based index
                string name = contacts[index].firstName + " " + contacts[index].lastName;
                contacts.erase(contacts.begin() + index); // Delete Selected Contact (index) from Vector 
                updatePhoneIndexMap(); // Update indexing in Phonebook
                cout << "Contact with the index " << index + 1 << " (" << name << ") has been removed." << endl;
            }
            else {
                cout << "No contact found with the given index." << endl;
            }
        }
        else if (identifier == "phone number") {
            if (phoneIndexMap.find(value) != phoneIndexMap.end()) {
                size_t index = phoneIndexMap[value];
                string name = contacts[index - 1].firstName + " " + contacts[index - 1].lastName;
                contacts.erase(contacts.begin() + index - 1); // Delete Selected Contact (index) from Vector 
                updatePhoneIndexMap(); // Update indexing in Phonebook
                cout << "Contact with the phone number " << value << " (" << name << ") has been removed." << endl;
            }
            else {
                cout << "No contact found with the given phone number." << endl;
            }
        }
        else {
            cout << "Invalid identifier." << endl;
        }
    }

/* Bookmark of a Contact is toggled depending on the passed identifier (phone# or index)*/
void Phonebook::bookmarkContact(const string& identifier, const string& value) {
        if (identifier == "index") {
            istringstream iss(value);
            int index;
            if (iss >> index && index >= 1 && index <= contacts.size()) {
                index -= 1; // Convert to 0-based index
                contacts[index].bookmarked = !contacts[index].bookmarked; // toggle bookmark
                string name = contacts[index].firstName + " " + contacts[index].lastName;
                cout << "Contact with the index " << index + 1 << " (" << name << ") has been " << (contacts[index].bookmarked ? "bookmarked." : "unbookmarked.") << endl;
            }
            else {
                cout << "Invalid index." << endl;
            }
        }
        else {
            cout << "Invalid identifier." << endl;
        }
    }

/* Sets new index in Phonebook if a Contact is removed/stored.*/
void Phonebook::updatePhoneIndexMap() {
        phoneIndexMap.clear();
        for (size_t i = 0; i < contacts.size(); ++i) {
            phoneIndexMap[contacts[i].phoneNumber] = i + 1;
        }
    }

//}
