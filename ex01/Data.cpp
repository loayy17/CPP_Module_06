#include "Data.hpp"
Data::Data() : intValue(0), strValue(""), boolValue(false), charValue('\0') {}
Data::~Data() {}
Data::Data(const Data& other) : intValue(other.intValue), strValue(other.strValue), boolValue(other.boolValue), charValue(other.charValue) {}
Data& Data::operator=(const Data& other) {
    if (this != &other) {
        intValue  = other.intValue;
        strValue  = other.strValue;
        boolValue = other.boolValue;
        charValue = other.charValue;
    }
    return *this;
}