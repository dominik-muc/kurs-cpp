// Dominik Muc, 345952, Lista 6

#include <iostream>
#include "polynomial.hpp"

int main() {
    Polynomial p1;
    std::cout << "Wprowadź wielomian w postaci: n a(n) a(n-1) ... a0: ";
    std::cin >> p1;
    std::cout << "Wprowadzony wielomian p1: " << p1 << std::endl;

    Polynomial p2(3);
    std::cout << "Wielomian p2 (stopień 3, domyślne współczynniki): " << p2 << std::endl;

    double factors[] = {1.0, 2.0, 3.0, 4.0};
    Polynomial p3(3, factors);
    std::cout << "Wielomian p3 z własnymi współczynnikami: " << p3 << std::endl;

    Polynomial p4({5.0, 4.0, 3.0, 2.0, 1.0});
    std::cout << "Wielomian p4 z listy inicjalizacyjnej: " << p4 << std::endl;

    Polynomial p5 = p3;
    std::cout << "Wielomian p5, kopia p3: " << p5 << std::endl;

    Polynomial p6 = std::move(p4);
    std::cout << "Wielomian p6, przeniesiony z p4: " << p6 << std::endl;

    p5 = p6;
    std::cout << "Wielomian p5 po przypisaniu kopiującym z p6: " << p5 << std::endl;

    p2 = std::move(p5);
    std::cout << "Wielomian p2 po przypisaniu przenoszącym z p5: " << p2 << std::endl;

    Polynomial sum = p1 + p2;
    std::cout << "Suma p1 + p2: " << sum << std::endl;

    Polynomial diff = p3 - p2;
    std::cout << "Różnica p3 - p2: " << diff << std::endl;

    Polynomial prod = p1 * p3;
    std::cout << "Iloczyn p1 * p3: " << prod << std::endl;

    Polynomial scalarProd = p1 * 3.5;
    std::cout << "Iloczyn skalarny p1 * 3.5: " << scalarProd << std::endl;

    p1 += p3;
    std::cout << "p1 po dodaniu p3: " << p1 << std::endl;

    p2 -= p3;
    std::cout << "p2 po odjęciu p3: " << p2 << std::endl;

    p3 *= p1;
    std::cout << "p3 po pomnożeniu przez p1: " << p3 << std::endl;

    p1 *= 2.5;
    std::cout << "p1 po pomnożeniu przez skalar 2.5: " << p1 << std::endl;

    double value = p2(1.5);
    std::cout << "Wartość p2 dla x=1.5: " << value << std::endl;

    double coeff = p3[2];
    std::cout << "Współczynnik przy x^2 w p3: " << coeff << std::endl;

    p3[2] = 6.0;
    std::cout << "p3 po zmianie współczynnika przy x^2: " << p3 << std::endl;

    try{
        Polynomial p7(-1, new double[1]{0});
    }
    catch(std::invalid_argument e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
