#ifndef __DATE_H__
#define __DATE_H__

#include <sstream>
#include "stdafx.h"

using namespace std;

namespace DateManipulations {
    const unsigned int MAXYEAR = 3000;
    const unsigned int MONTHS = 12;
    const unsigned int DAYS_IN_YEAR = 365;
    const unsigned int DAYS_IN_LEAP_YEAR = 366;

    struct Date {
        string form() const;
        unsigned int d, m, y;

        Date& operator= (unsigned int days);
        Date& operator- (unsigned int days);
        unsigned int operator- (Date& rhs);

        Date(unsigned int day = 0, unsigned int month = 0, unsigned int year = 0) : d(day), m(month), y(year) {}

    private:
        enum months { def, jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
        unsigned int daysInMonths[MONTHS + 1] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        void check();
        static bool isLeap(unsigned int year);
    };
}
#endif //__DATE_H__