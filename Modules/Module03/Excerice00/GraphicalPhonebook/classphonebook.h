#pragma once

#include "classcontact.h"

#ifndef CLASSPHONEBOOK_H
#define CLASSPHONEBOOK_H


class Phonebook {
private:
    vector<Contact> contacts_;
    unordered_map<string, size_t> phoneIndexMap_;
public:
    Phonebook();
    void addContact(const string& firstName, const string& lastName, const string& phoneNumber, const string& nickname, const string& email);
    void searchContacts(const string& mode, const string& criteria);
    void removeContact(const string& identifier, const string& value);
    void bookmarkContact(const string& identifier, const string& value);
    void updatePhoneIndexMap();
};


#endif // CLASSPHONEBOOK_H
