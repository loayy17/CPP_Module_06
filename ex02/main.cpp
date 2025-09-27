#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <cmath>
Base* generate(void) {
    int randomChoice = rand() % 3;
    switch (randomChoice) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return 0;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {
    }
    std::cout << "Unknown Type" << std::endl;
}

int main() {
    Base* base;
    std::cout << "| # | Pointer | Reference |" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "---------------------------------------------" << std::endl;
        base = generate();
        std::cout << "| " << (i + 1) << " | " << std::endl;
        std::cout << "\033[31m  ";
        identify(base);
        std::cout << " \033[0m";
        std::cout << "\033[32m ";
        identify(*base);
        std::cout << " \033[0m";
        std::cout << "---------------------------------------------" << std::endl;
        delete base;
    }
    return 0;
}
