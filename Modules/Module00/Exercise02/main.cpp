#include "include/convert.h"

int main(int argc, char* argv[]) {
    //Print to terminal that argv does not include all needed information (/path/command/string)
    if (argc < 3) {
        cout << "Usage: ./convert {command} {string}" << endl;
    }
    //Extract cmd input (/path/command/string)
    string file_path = argv[0];
    string command = argv[1]; 
    string str = argv[2];
    //Don't forget that a string input can be separated by spaces/tablogs.
    for(int i = 3; i<argc; i++){
        str.append(" ");
        str.append(argv[i]);
    }
    //Call functions for command "up" oder "down" and print to terminal
    string result;
    if (command == "up") {
        result = convertUppercase(str);
    } else if (command == "down") {
        result = convertLowercase(str);
    } else {
        cout << "Invalid command" << endl;
    }
    cout << result << endl;
}