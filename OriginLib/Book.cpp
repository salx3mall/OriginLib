#include "stdafx.h"
#include "Book.h"

using namespace std;

const string& Book::getTitle() const {
    return this->title;
}

const string& Book::getAuthor() const {
    return this->author;
}

const string& Book::getPublisher() const {
    return this->publisher;
}

const string& Book::getISBN() const {
    return this->ISBN;
}

const string& Book::getURL() const {
    return this->URL;
}

unsigned int Book::getId() const {
    return this->id;
}

unsigned int Book::getReleaseYear() const {
    return this->releaseYear;
}

size_t Book::getPages() const {
    return this->pages;
}

size_t Book::getReminder() const {
    return this->reminder;
}

const string& Book::getLanguage() const {
    return this->language;
}

const string Book::formCiteName() const {
    std::stringstream result;
    result << author << ". " << title << " / " << author << ". - " << publisher << ", " << releaseYear << ". - " << pages << " p." << endl;
    return result.str();
}

bool Book::isModified() const {
    return modified;
}

ostream& operator<<(ostream& stream, Book& book) {
    stream << "The next book is created (updated):" << endl;
    stream << book.formCiteName();
    return stream;
}