#ifndef __NAME_H__
#define __NAME_H__

using namespace std;

struct Name {
    Name(const string& first = "", const string& second = "", const string& last = "");

    const string& getFirstName() const;
    const string& getSecondName() const;
    const string& getSurname() const;

    const string formShortNameFirst() const;
    const string formShortNameLast() const;

private:
    string firstName;
    string secondName;
    string surname;
};

#endif //__NAME_H__