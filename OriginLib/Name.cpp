#include "stdafx.h"
#include "Name.h"

using namespace std;

Name::Name(const string& first = "", const string& second = "", const string& last = "") : firstName(first), secondName(second), surname(last) {}

const string& Name::getFirstName() const {
    return this->firstName;
}
const string& Name::getSecondName() const {
    return this->secondName;
}
const string& Name::getSurname() const {
    return this->surname;
}

const string Name::formShortNameFirst() const {
    string result;
    result += firstName[0];
    result += ". ";
    if (!secondName.empty()) {
        result += secondName[0];
        result += ". ";
    }
    result += surname;
    return result;
}

const string Name::formShortNameLast() const {
    string result = surname + " ";
    result += firstName[0] + ". ";
    if (!secondName.empty())
        result += secondName[0] + ". ";
    return result;
}