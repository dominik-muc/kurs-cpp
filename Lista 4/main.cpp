// Dominik Muc, 345952, Lista 4

#include "number.hpp"
#include <iostream>

int main(){
    Number a(14);
    a.Set(21);
    a.Set(28);
    a.Set(35);
    std::cout << "a: 14, (21, 28, 35)" << std::endl;
    for(int i = 0; i < 5; i++){
        std::cout << a.Get() << std::endl;
        a.Undo();
    }
    a.Set(42);
    Number b(a);
    std::cout << "b: (21, 42)" << std::endl;
    for(int i = 0; i < 5; i++){
        std::cout << b.Get() << std::endl;
        b.Undo();
    }
    b.Set(49);
    b.Set(56);
    Number c(b);
    c.Set(63);
    std::cout << "c: (56, 63)" << std::endl;
    for(int i = 0; i < 5; i++){
        std::cout << c.Get() << std::endl;
        c.Undo();
    }
    Number d;
    d = c;
    d.Set(70);
    std::cout << "d: (0, 56, 70)" << std::endl;
    for(int i = 0; i < 5; i++){
        std::cout << d.Get() << std::endl;
        d.Undo();
    }
    return 0;
}