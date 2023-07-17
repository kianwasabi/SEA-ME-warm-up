#pragma once

#include "classcontact.h"
#include <QDebug>

#ifndef CLASSPHONEBOOK_H
#define CLASSPHONEBOOK_H

class Phonebook {
private:
    vector<Contact> contacts_;
    unordered_map<string, size_t> phoneIndexMap_;
public:
    //Default Construtor
    Phonebook();
    // Destructor
    ~Phonebook();
    // Setter functions
    bool addContact(const string& firstName, const string& lastName, const string& phoneNumber, const string& nickname, const string& email);
    // Getter functions
    vector<vector<string>> searchContacts(const string& mode, const string& criteria) const;
    // Update functions
    bool bookmarkContact(const string& identifier, const string& value);
    // Delete functions
    bool removeContact(const string& identifier, const string& value);
    // other function
    void updatePhoneIndexMap();
};


#endif // CLASSPHONEBOOK_H
