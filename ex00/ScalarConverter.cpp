#include "ScalarConverter.hpp"
#include "TypeConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

void ScalarConverter::convert(const std::string& literal) {
    TypeConverter type = TypeConverter::fromLiteral(literal);
    type.printConversions();
}
