#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>
class Data {
   public:
    int         intValue;
    std::string strValue;
    bool        boolValue;
    char        charValue;
    Data();
    ~Data();
    Data(const Data& other);
    Data& operator=(const Data& other);
};

#endif