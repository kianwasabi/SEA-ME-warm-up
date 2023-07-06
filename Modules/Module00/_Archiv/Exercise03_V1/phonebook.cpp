#include "../include/phonebook.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {
    Phonebook phonebook;

    string command;
    while (true) {
        cout << "Enter command: ";
        getline(cin, command);
        istringstream iss(command);
        string operation;
        iss >> operation;

        if (operation == "ADD") {
            string firstName, lastName, phoneNumber, nickname;
            iss >> firstName >> lastName >> phoneNumber >> nickname;
            phonebook.addContact(firstName, lastName, phoneNumber, nickname);
        }
        else if (operation == "SEARCH") {
            string mode, criteria;
            iss >> mode >> ws;
            getline(iss, criteria);
            phonebook.searchContacts(mode, criteria);
        }
        else if (operation == "REMOVE") {
            string identifier, value;
            iss >> identifier >> value;
            phonebook.removeContact(identifier, value);
        }
        else if (operation == "BOOKMARK") {
            string identifier, value;
            iss >> identifier >> value;
            phonebook.bookmarkContact(identifier, value);
        }
        else if (operation == "EXIT") {
            cout << "Program has been ended." << endl;
            break;
        }
        else {
            cout << "Invalid command." << endl;
        }
    }
    return 0;
}


