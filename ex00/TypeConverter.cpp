#include "TypeConverter.hpp"
#include <cstdlib>
#include <iomanip>
TypeConverter::TypeConverter(Type t) : _type(t), _charValue(0), _intValue(0), _floatValue(0.0f), _doubleValue(0.0) {}

TypeConverter::TypeConverter(Type t, char c) : _type(t), _charValue(c), _intValue(0), _floatValue(0.0f), _doubleValue(0.0) {}

TypeConverter::TypeConverter(Type t, int i) : _type(t), _charValue(0), _intValue(i), _floatValue(0.0f), _doubleValue(0.0) {}

TypeConverter::TypeConverter(Type t, float f) : _type(t), _charValue(0), _intValue(0), _floatValue(f), _doubleValue(0.0) {}

TypeConverter::TypeConverter(Type t, double d) : _type(t), _charValue(0), _intValue(0), _floatValue(0.0f), _doubleValue(d) {}

TypeConverter::TypeConverter(Type t, const std::string& s)
    : _type(t), _charValue(0), _intValue(0), _floatValue(0.0f), _doubleValue(0.0), _stringValue(s) {}

TypeConverter TypeConverter::fromLiteral(const std::string& literal) {
    // Special values
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff") {
        return TypeConverter(SPECIAL, literal);
    }

    // Char literal: either a single printable non-digit character, or a quoted char like 'a'
    if ((literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) ||
        (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'' && std::isprint(literal[1]))) {
        char c = (literal.size() == 1) ? literal[0] : literal[1];
        return TypeConverter(CHAR, c);
    }

    // Int
    char* end;
    long  val = strtol(literal.c_str(), &end, 10);
    if (*end == '\0' && val >= -2147483648 && val <= 2147483647)
        return TypeConverter(INT, static_cast<int>(val));

    // Float
    if (!literal.empty() && literal[literal.size() - 1] == 'f') {
        std::string floatPart = literal.substr(0, literal.size() - 1);
        char*       endFloat;
        float       f = strtof(floatPart.c_str(), &endFloat);
        if (*endFloat == '\0')
            return TypeConverter(FLOAT, f);
    }

    // Double
    char*  endDouble;
    double d = strtod(literal.c_str(), &endDouble);
    if (*endDouble == '\0')
        return TypeConverter(DOUBLE, d);

    return TypeConverter(INVALID);
}

void TypeConverter::printConversions() const {
    switch (_type) {
        case INVALID:
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            break;

        case CHAR:
            std::cout << "char: '" << _charValue << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(_charValue) << std::endl;
            std::cout << "float: " << static_cast<float>(_charValue) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(_charValue) << ".0" << std::endl;
            break;

        case INT: {
            int c = _intValue;
            std::cout << "char: "
                      << ((c < 0 || c > 127) ? "impossible" : (!isprint(c) ? "Non displayable" : ("'" + std::string(1, static_cast<char>(c)) + "'")))
                      << std::endl;
            std::cout << "int: " << c << std::endl;
            std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
            break;
        }

        case FLOAT: {
            float f     = _floatValue;
            int   c     = static_cast<int>(f);
            bool  isInt = (f - c == 0);
            std::cout << "char: "
                      << ((!isInt || c < 0 || c > 127) ? "impossible"
                                                       : (!isprint(c) ? "Non displayable" : ("'" + std::string(1, static_cast<char>(c)) + "'")))
                      << std::endl;
            std::cout << "int: " << static_cast<int>(f) << std::endl;
            std::cout << "float: " << f << (isInt ? ".0" : "") << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << (isInt ? ".0" : "") << std::endl;
            break;
        }

        case DOUBLE: {
            double d     = _doubleValue;
            int    c     = static_cast<int>(d);
            bool   isInt = (d - c == 0);
            std::cout << "char: "
                      << ((!isInt || c < 0 || c > 127) ? "impossible"
                                                       : (!isprint(c) ? "Non displayable" : ("'" + std::string(1, static_cast<char>(c)) + "'")))
                      << std::endl;
            std::cout << "int: " << static_cast<int>(d) << std::endl;
            std::cout << "float: " << static_cast<float>(d) << (isInt ? ".0" : "") << "f" << std::endl;
            std::cout << "double: " << d << (isInt ? ".0" : "") << std::endl;
            break;
        }

        case SPECIAL:
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            if (_stringValue.find("nan") != std::string::npos) {
                std::cout << "float: nanf\n";
                std::cout << "double: nan\n";
            } else if (_stringValue.find("+inf") != std::string::npos) {
                std::cout << "float: +inff\n";
                std::cout << "double: +inf\n";
            } else if (_stringValue.find("-inf") != std::string::npos) {
                std::cout << "float: -inff\n";
                std::cout << "double: -inf\n";
            }
            break;
    }
}
