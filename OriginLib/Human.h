#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "Name.h"
#include "Address.h"
#include "Date.h"

using namespace std;
using namespace DateManipulations;

class Human {
protected:
    Human(const Name& nm, const Date& date, const Address& addr) : name(nm), birthDate(date), address(addr) {};
    Name name;
    Date birthDate;
    Address address;
};

#endif //__HUMAN_H__