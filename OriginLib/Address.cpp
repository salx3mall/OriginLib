#include "stdafx.h"
#include "Address.h"

string Address::form() {
    string result = postalCode + ", ";
    result += country + ", " + region + " region, " + locality + ", " + street + " str., " + house + ", " + houseExtension;
    return result;
}

Address::Address(const string& post = "", const string& state = "", const string& district = "", const string& city = "", const string& str = "", const string& home = "", const string& flat = "") {
    postalCode = post.empty() ? "Unknown postal code" : post;
    country = state.empty() ? "Unknown" : state;
    region = district.empty() ? "Unknown" : district;
    locality = city.empty() ? "Unstated city" : city;
    street = str.empty() ? "None" : str;
    house = home.empty() ? "Unknown number" : home;
    houseExtension = flat.empty() ? "No flat" : flat;
}