#pragma once

#ifndef CLASSCONTACT_H
#define CLASSCONTACT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <QDebug>

using namespace std;

struct Contact {
public:
    string firstName_;
    string lastName_;
    string phoneNumber_;
    string email_;
    string nickname_;
    bool bookmarked_;
    Contact(const string& first, const string& last, const string& phone, const string& nick, const string& email);
};

#endif // CLASSCONTACT_H
