#include <iostream>
// casting Tutorial in c++ 98
// 1 static_cast
// 2 dynamic_cast
// 3 const_cast
// 4 reinterpret_cast
// 5 C-style cast
// 1 static_cast
void static_cast_example() {
    // c-style vs static_cast
    // c-style cast is not safe because it can perform multiple types of casts (const_cast, static_cast, reinterpret_cast) in one operation
    // static_cast is safer because it only performs one type of cast at a time
    // static_cast is checked at compile time, while c-style cast is not
    // static_cast cannot cast away constness, while c-style cast can
    // static_cast is more readable and easier to find in the code, while c-style cast is harder to find
    // static_cast is more explicit about the type of conversion being performed
    // Example of c-style cast
    int  a = 10;
    double b = (double)a; // تحويل int إلى double باستخدام c-style cast
    std::cout << "c-style cast: " << b << std::endl;
    // Interesting example of static_cast
    int i = 10;
    double d = static_cast<double>(i); // تحويل int إلى double
    float f = static_cast<float>(i);   // تحويل int إلى float
    bool b = static_cast<bool>(i);     // تحويل int إلى bool
    char c = static_cast<char>(i);   // تحويل int إلى char
    long l = static_cast<long>(i);   // تحويل int إلى long
    short s = static_cast<short>(i); // تحويل int إلى short
    // 
    std::cout << "static_cast examples:" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "double: " << d << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "bool: " << b << std::endl;
    std::cout << "char: " << c << std::endl;
    std::cout << "long: " << l << std::endl;
    std::cout << "short: " << s << std::endl;
    // converters from string to others
    std::string str = "123";
    bool bnum = static_cast<bool>(std::stoi(str)); // تحويل string إلى bool باستخدام دالة من المكتبة
    int num = std::stoi(str); // تحويل string إلى int باستخدام دالة من المكت
    float fnum = std::stof(str); // تحويل string إلى float باستخدام دالة من المكتبة
    double dnum = std::stod(str); // تحويل string إلى double باستخدام دالة من المكتبة
    char ch = static_cast<char>(std::stoi(str)); // تحويل string إلى char باستخدام دالة من المكتبة
    std::cout << "string to int: " << num << std::endl;
    std::cout << "string to float: " << fnum << std::endl;
    std::cout << "string to double: " << dnum << std::endl;
    std::cout << "string to char: " << ch << std::endl;
    std::cout << "string to bool: " << bnum << std::endl;
    //
}

// 2 dynamic_cast
void dynamic_cast_example() {
    // class dynamic_cast example with virtual destructor 
    // it must base be virtual destructor because dynamic_cast uses RTTI (Run Time Type Information)
    // RTTI is a mechanism that allows the type of an object to be determined at runtime
    // the base class must have at least one virtual function to enable RTTI
    // if dynamic_cast fails, it returns nullptr for pointer types or throws std::bad_cast for reference types
    // uses: safe downcasting in inheritance hierarchies 
    // typeinfo is function that returns the type of the object at runtime and it not allowed in c++98
    // Example of dynamic_cast
    class Base {
    public:
        virtual ~Base() {}
    };
    class Derived1 : public Base {
    public:
        void show() { std::cout << "Derived1 class" << std::endl; }
    };
    class Derived2 : public Base {
    public:
        void show() { std::cout << "Derived2 class" << std::endl; }
    };
    Base* b1 = new Derived1();
    Base* b2 = new Derived2();
    Derived1* d1 = dynamic_cast<Derived1*>(b1);
    if (d1) {
        d1->show();
    } else {
        std::cout << "Failed to cast b1 to Derived1*" << std::endl;
    }
    Derived2* d2 = dynamic_cast<Derived2*>(b1);
    if (d2) {
        d2->show();
    } else {
        std::cout << "Failed to cast b1 to Derived2*" << std::endl;
    }
    delete b1;
    delete b2;
}

// 3 const_cast
void const_cast_example() {
    // const_cast is used to add or remove the const or volatile qualifier from a variable
    // it is the only cast that can do this
    // it is used to modify a variable that is originally declared as const
    // it is used to pass a const variable to a function that takes a non-const parameter
    // it is used to cast away constness from a pointer or reference
    // it is not safe to modify a variable that is originally declared as const
    // Example of const_cast
    const int  a = 10;
    int*       p = const_cast<int*>(&a); // إزالة const من المؤشر
    //*p = 20; // تعديل القيمة (غير آمن، قد يؤدي إلى سلوك غير معرف)
    std::cout << "const_cast example:" << std::endl;
    std::cout << "Original const value: " << a << std::endl;
    std::cout << "Value after const_cast (attempted modification commented out): " << *p << std::endl;
    // Example of const_cast with function
    void func(int* x) {
        *x = 20; // تعديل القيمة
    }
    const int b = 30;
    func(const_cast<int*>(&b)); // تمرير const إلى دالة تأخذ non-const
    std::cout << "Value of b after func call (attempted modification commented out): " << b << std::endl;
}

// 4 reinterpret_cast
#include <cstdint>
struct Data {
    int  x;
    char y;
    bool z;
};
void reinterpret_cast_example() {
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
    // 4️⃣ تحويل المؤشر إلى نوع غير مرتبط (مثلاً من Data* إلى int*)
    int* intPtr = reinterpret_cast<int*>(ptr);
    std::cout << "\n=== After reinterpret_cast to int* ===" << std::endl;
    std::cout << "intPtr points to value: " << *intPtr << std::endl; // قد لا يكون ذا معنى
}

// 5 C-style cast
void c_style_cast_example() {
    // C-style cast is a combination of static_cast, const_cast, and reinterpret_cast
    // it is not safe because it can perform multiple types of casts in one operation
    // it is not checked at compile time
    // it can cast away constness
    // it is harder to find in the code
    // it is less explicit about the type of conversion being performed
    // Example of C-style cast
    int  a = 10;
    double b = (double)a; // تحويل int إلى double باستخدام C-style cast
    std::cout << "C-style cast: " << b << std::endl;
    // Interesting example of C-style cast
    int i = 10;
    double d = (double)i; // تحويل int إلى double
    float f = (float)i;   // تحويل int إلى float
    bool b = (bool)i;     // تحويل int إلى bool 
    char c = (char)i;   // تحويل int إلى char
    long l = (long)i;   // تحويل int إلى long
    short s = (short)i; // تحويل int إلى short
    // 
    std::cout << "C-style cast examples:" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "double: " << d << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "bool: " << b << std::endl;
    std::cout << "char: " << c << std::endl;
    std::cout << "long: " << l << std::endl;
    std::cout << "short: " << s << std::endl;
    // converters from string to others
    std::string str = "123";
    bool bnum = (bool)std::stoi(str); // تحويل string إلى bool باستخدام دالة من المكتبة
    int num = std::stoi(str); // تحويل string إلى int باستخدام دالة من المكتبة
    float fnum = std::stof(str); // تحويل string إلى float باستخدام دالة من المكتبة
    double dnum = std::stod(str); // تحويل string إلى double باستخدام دالة من المكتبة
    char ch = (char)std::stoi(str); // تحويل string إلى char باستخدام دالة من المكتبة
    std::cout << "string to int: " << num << std::endl;
    std::cout << "string to float: " << fnum << std::endl;
    std::cout << "string to double: " << dnum << std::endl;
    std::cout << "string to char: " << ch << std::endl;
    std::cout << "string to bool: " << bnum << std::endl;
    //
}

