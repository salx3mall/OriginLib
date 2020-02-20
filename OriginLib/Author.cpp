#include "stdafx.h"
#include "Author.h"

Author(const Name& name, const Date& birth, const Address& addr, const string& description = "") :
    Human(name, birth, addr), biography(description) {
};

void Author::linkWrittenBook(Book& book) {
    writtenBooks.push_back(make_shared<Book>(book));
};