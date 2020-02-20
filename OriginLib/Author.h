#ifndef __AUTHOR_H__
#define __AUTHOR_H__

#include <vector>
#include <memory>

#include "Human.h"
#include "Name.h"

using namespace std;

class Author : Human {
public:
    Author() = default;
    Author(const Name& name, const Date& birth, const Address& addr, const string& description = "");
    Author(Author&) = delete;
    Author& operator= (Author&) = delete;

    void linkWrittenBook(Book& book);

    ~Author() = default;
private:
    string biography;
    vector<shared_ptr<Book>> writtenBooks;
};

#endif //__AUTHOR_H__