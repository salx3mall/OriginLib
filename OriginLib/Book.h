#ifndef __BOOK_H__
#define __BOOK_H__

#include <sstream>
#include "stdafx.h"

using namespace std;

enum Language;
class Book {
public:
    inline const string& getTitle() const;
    inline const string& getAuthor() const;
    inline const string& getPublisher() const;
    inline const string& getISBN() const;
    inline const string& getURL() const;
    inline unsigned int getId() const;
    inline unsigned int getReleaseYear() const;
    inline size_t getPages() const;
    inline size_t getReminder() const;
    inline const string& getLanguage() const;
    const string formCiteName() const;
    bool isModified() const;
    friend ostream& operator<<(ostream& stream, Book& book);

private:
    string title;
    string author;
    string publisher;
    string ISBN;
    string URL;
    unsigned int id;
    unsigned int releaseYear;
    size_t pages;
    size_t reminder;
    string language;
    bool modified;
};

#endif //__BOOK_H__