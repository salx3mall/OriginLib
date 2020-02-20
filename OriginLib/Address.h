#ifndef __ADDRESS_H__
#define __ADDRESS_H__

using namespace std;

struct Address {
    Address(const string& post = "", const string& state = "", const string& district = "", const string& city = "", const string& str = "", const string& home = "", const string& flat = "");

    string form();

private:
    string postalCode;
    string country;
    string region;
    string locality;
    string street;
    string house;
    string houseExtension;
};

#endif //__ADDRESS_H__