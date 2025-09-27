#include "Serializer.hpp"
int main() {
    Data* data = new Data();
    data->intValue  = 42;
    data->strValue  = "Hello, World!";
    data->boolValue = true;
    data->charValue = 'A';
    uintptr_t raw  = Serializer::serialize(data);
    Data*     newData = Serializer::deserialize(raw);
    std::cout << "Original Data:\n";
    std::cout << "intValue: " << data->intValue << "\n";
    std::cout << "strValue: " << data->strValue << "\n";
    std::cout << "boolValue: " << (data->boolValue ? "true" : "false") << "\n";
    std::cout << "charValue: " << data->charValue << "\n";
    std::cout << "\nDeserialized Data:\n";
    std::cout << "intValue: " << newData->intValue << "\n";
    std::cout << "strValue: " << newData->strValue << "\n";
    std::cout << "boolValue: " << (newData->boolValue ? "true" : "false") << "\n";
    std::cout << "charValue: " << newData->charValue << "\n";
    delete data;
    return 0;
}