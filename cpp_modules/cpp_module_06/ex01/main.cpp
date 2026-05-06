#include <iostream>
#include <string>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data *p = new Data();
    p->name = "Dev";
    p->age = 32;

    std::uintptr_t raw;
    raw = Serializer::serialize(p);
    Data *p1 = Serializer::deserialize(raw);
    if (p1 == p) {
        std::cout << "Success, p: " << p << ", p1: " << p1 << ", raw: " << raw << std::endl;
    } else {
        std::cout << "Unsucessful, p: " << p << ", p1: " << p1 << ", raw: " << raw << std::endl;
    }
    return 0;
}