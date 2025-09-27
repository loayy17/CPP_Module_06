#ifndef TYPECONVERTER_HPP
#define TYPECONVERTER_HPP

#include <iostream>
#include <string>

class TypeConverter {
   public:
    enum Type { CHAR, INT, FLOAT, DOUBLE, SPECIAL, INVALID };

    // Constructors for different types
    TypeConverter(Type t = INVALID);
    TypeConverter(Type t, char c);
    TypeConverter(Type t, int i);
    TypeConverter(Type t, float f);
    TypeConverter(Type t, double d);
    TypeConverter(Type t, const std::string& s);

    static TypeConverter fromLiteral(const std::string& literal);
    void                 printConversions() const;

   private:
    Type        _type;
    char        _charValue;
    int         _intValue;
    float       _floatValue;
    double      _doubleValue;
    std::string _stringValue;
};

#endif
