#include "classcontact.h"

Contact::Contact(const string& first, const string& last, const string& phone, const string& nick, const string& email)
    : firstName_(first), lastName_(last), phoneNumber_(phone), nickname_(nick), email_(email), bookmarked_(false) {}
