#include <iostream>
#include <cstdint>

struct Data {
    int  x;
    char y;
    bool z;
};

int main() {
    
    Data  d   = {300, 'A', true}; // متغير Data
    Data* ptr = &d;               // مؤشر للمتغير

    std::cout << "=== Original Data ===" << std::endl;
    std::cout << "Address of d: " << ptr << std::endl;
    std::cout << "d.x = " << d.x << ", d.y = " << d.y << ", d.z = " << d.z << std::endl;

    // 1️⃣ تحويل المؤشر إلى عدد صحيح (serialize)
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    std::cout << "\n=== After reinterpret_cast to uintptr_t ===" << std::endl;
    std::cout << "Raw integer value (address as number): " << raw << std::endl;

    // 2️⃣ تحويل العدد الصحيح مرة أخرى إلى مؤشر (deserialize)
    Data* newPtr = reinterpret_cast<Data*>(raw);
    std::cout << "\n=== After reinterpret_cast back to Data* ===" << std::endl;
    std::cout << "Address of newPtr: " << newPtr << std::endl;
    std::cout << "newPtr->x = " << newPtr->x << ", newPtr->y = " << newPtr->y << ", newPtr->z = " << newPtr->z << std::endl;

    // 3️⃣ قراءة أول بايت من المتغير reinterpret_cast إلى char*
    char* bytePtr = reinterpret_cast<char*>(ptr);
    std::cout << "\n=== Reading bytes of Data as char* ===" << std::endl;
    for (size_t i = 0; i < sizeof(Data); i++) {
        std::cout << "Byte " << i << " = " << static_cast<int>(bytePtr[i]) << std::endl;
    }

    // 
    return 0;
}
