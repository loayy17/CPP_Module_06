#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* pointer) {
    return reinterpret_cast<uintptr_t>(pointer);
}
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}