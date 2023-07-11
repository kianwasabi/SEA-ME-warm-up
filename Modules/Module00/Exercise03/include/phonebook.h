#ifndef PHONEBOOK
#define PHONEBOOK

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

//namespace Phonebook{
struct Contact {
public:    
    string firstName;
    string lastName;
    string phoneNumber;
    string nickname;
    bool bookmarked;
    Contact(const string& first, const string& last, const string& phone, const string& nick)
        : firstName(first), lastName(last), phoneNumber(phone), nickname(nick), bookmarked(false) {} 
};

class Phonebook {
private:
    vector<Contact> contacts;
    unordered_map<string, size_t> phoneIndexMap;
public:
    Phonebook();
    void addContact(const string& firstName, const string& lastName, const string& phoneNumber, const string& nickname);
    void searchContacts(const string& mode, const string& criteria);
    void removeContact(const string& identifier, const string& value);
    void bookmarkContact(const string& identifier, const string& value);
    void updatePhoneIndexMap();
};
//}
#endif // PHONEBOOK

