#include "stdafx.h"
#include "Date.h"

using namespace DateManipulations;

string Date::form() const {
    stringstream result;
    result << d << "/" << m << "/" << y;
    return result.str();
}

unsigned int Date::operator- (Date& rhs) {
    unsigned int d1, d2, m1, m2, y1, y2;
    unsigned int days = 0;
    int sign = 0;
    if (y > rhs.y || (y == rhs.y && m > rhs.m) || (y == rhs.y && m == rhs.m && d > rhs.d)) {
        d1 = d;
        m1 = m;
        y1 = y;
        d2 = rhs.d;
        m2 = rhs.m;
        y2 = rhs.y;
        sign = 1;
    }
    else {
        d1 = rhs.d;
        m1 = rhs.m;
        y1 = rhs.y;
        d2 = d;
        m2 = m;
        y2 = y;
        sign = -1;
    }
    if (d1 == d2 && m1 == m2 && y1 == y2)
        return 0;
    
    while (true) {
        if (m1 == m2 && y1 == y2) {
            days += d1 - d2;
            break;
        }
        days += d1;
        m1--;
        if (m1 == def) {
            m1 = dec;
            y1--;
        }
        if (isLeap(y1))
            daysInMonths[feb] = 29;
        else
            daysInMonths[feb] = 28;
        d1 = daysInMonths[m1];
    }
    
    return days * sign;
}


Date& Date::operator-(unsigned int days) { // Probably, I'll never need this feature, just wanted to implement it as it's a training project
    while (true) {
        if (days < d) {
            days -= d;
            break;
        }
        days -= d;
        m--;
        if (m == def) {
            m = dec;
            y--;
            if (y == 0000)
                ; //TODO: throw BadDate("Oooops! Seems like we gotta wrong date here!\n");
        }
        if (isLeap(y))
            daysInMonths[feb] = 29;
        else
            daysInMonths[feb] = 28;
        d = daysInMonths[m];
    }
    return *this;
}

//Counts date by amount of days, passed since 1/1/0001
Date& Date::operator= (unsigned int days) {
    if (!days)
        ;//TODO: throw BadDate("Oooops! Seems like we gotta wrong date here!\n");
    for (unsigned int year = 1; year <= MAXYEAR; year++) {
        const bool leap = isLeap(year);
        if (leap)
            daysInMonths[feb] = 29;
        else
            daysInMonths[feb] = 28;

        if ((days <= DAYS_IN_YEAR && !leap) || (days <= DAYS_IN_LEAP_YEAR && leap)) {
            y = year;
            for (unsigned int month = 0; month <= MONTHS; month++) {
                if (days <= daysInMonths[month]) {
                    m = month;
                    d = days;
                    break;
                }
                else
                    days -= daysInMonths[month];
            }
        }

        else {
            if (leap)
                days -= DAYS_IN_LEAP_YEAR;
            else
                days -= DAYS_IN_YEAR;
        }
    }
    return *this;
}

void Date::check() {
    if ((d == 0 || d > 31) || (m == def || m > months::dec) || y == 0 || //wrong day, month or year
        (d == 31 && (m == apr || m == jun || m == sep || m == nov)) || // this months shouldn't have more than 30 days
        (d == 30 && m == feb) || // same with 30 days in february
        (d == 29 && m == feb && !isLeap(y))) { // the 29th of february - in leap years only
        ;//TODO: throw BadDate("Oooops! Seems like we gotta wrong date here!\n");
    }
}


bool Date::isLeap(unsigned int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}