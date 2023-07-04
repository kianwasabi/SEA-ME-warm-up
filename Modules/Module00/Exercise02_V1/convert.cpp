#include <iostream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
/*
convertUppercase converts all lowercase characters in the input string to uppercase 
and returns the modified string while leaving non-alphabetic characters unchanged.
1)The function takes a const string& str as input, indicating that 
it expects a constant reference to a string object as the argument.
2)A new string variable named ret is created and initialized with the value of the input string str. 
This allows us to make modifications to the new string without affecting the original input string.
3)The code then enters a loop that iterates through each character c in the ret string using a range-based for loop.
4)Inside the loop, the isalpha function is used to check if the character c is an alphabet letter.
5)If the character c is both an alphabet letter and lowercase (as determined by the islower function), the toupper function is called to convert the character to its uppercase equivalent.
6)After the loop completes, the modified ret string is returned as the result of the function.
*/
string convertUppercase(const string& str) {
    string ret = str;
    for (char& c : ret) {
        if (isalpha(c) && islower(c)) {
            c = toupper(c);
        }
    }
    return ret;
}
/*Does the same as convertUppercase just to Lowercase :) */
string convertLowercase(const string& str) {
    string ret = str;
    // loop through char array and use tolower function for each char in char array
    for (char& c : ret) {
        if (isalpha(c) && isupper(c)) {
            c = tolower(c);
        }
    }
    return ret;
}
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