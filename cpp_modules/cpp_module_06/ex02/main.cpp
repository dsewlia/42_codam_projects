#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

Base *generate()
{
    int random = (std::rand() + std::time(nullptr)) % 3;

    if (random == 0) {
        std::cout << "Generated A" << std::endl;
        return new A;
    } else if (random == 1) {
        std::cout << "Generated B" << std::endl;
        return new B;
    } else {
        std::cout << "Generated C" << std::endl;
        return new C;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return ;
    } catch (std::exception &e) {
        (void) e;
    }
    try {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception &e) {
        (void) e;
    }
    try {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception &e) {
        (void) e;
    }
    std::cout << "Unknown" << std::endl;
}

int main(void)
{
    Base *b = generate();
    Base &bRef = *b;
    identify(b);
    identify(bRef);
    delete b;
    return 0;
}