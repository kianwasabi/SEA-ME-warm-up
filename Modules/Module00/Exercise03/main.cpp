#include "include/phonebook.h"

int main() {
    Phonebook phonebook;

    string command;
    while (true) {
        cout << "--- Old Phonebook Application ---" << endl;
        cout << "Instructions:" << endl;
        cout << "CMD1: ADD firstname lastname phonenumber nickname" << endl;
        cout << "StringStream is seperated by spaces. If first name consists of to names like 'Kian David' please type 'Kian-David' instead." << endl;
        cout << "Contacts are stored in this format: Index, First Name, Last Name, Phone Number, Nickname, Bookmarked" << endl;
        cout << "CMD2: SEARCH {all/index} {Null/value}" << endl;
        cout << "CMD3: REMOVE {index/phonenumber} {value}" << endl;
        cout << "CMD3: BOOKMARK {index} {value}" << endl;
        cout << "CMD4: EXIT" << endl;
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