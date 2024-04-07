// Dominik Muc, 345952, Lista 5

#include <iostream>
#include "queue.hpp"

int main() {
    Queue q1(5);
    q1.push("Jabłko");
    q1.push("Banan");
    std::cout << "Kolejka po dodaniu 'Jabłko' i 'Banan': " << q1.pop() << ", " << q1.pop() << std::endl;

    Queue q2(10);
    q2.push("Marchew");
    std::cout << "Kolejka po dodaniu 'Marchew': " << q2.peek() << std::endl;

    Queue q3({"Pies", "Słoń", "Żaba"});
    std::cout << "Kolejka utworzona z listy inicjalizacyjnej: ";
    while (q3.length() > 0) {
        std::cout << q3.pop() << " ";
    }
    std::cout << std::endl;

    q2.push("Winogrono");
    Queue q4 = q2;
    std::cout << "Kolejka po konstruktorze kopiowania: " << q4.pop() << std::endl;

    q1.push("Miód");
    q4 = q1;
    std::cout << "Kolejka po operatorze kopiowania: " << q4.pop() << std::endl;

    Queue q5 = std::move(q2);
    std::cout << "Kolejka po konstruktorze przenoszącym: ";
    while (q5.length() > 0) {
        std::cout << q5.pop() << " ";
    }
    std::cout << std::endl;

    q1.push("Lody");
    q5 = std::move(q1);
    std::cout << "Kolejka po operatorze przenoszącym: ";
    while (q5.length() > 0) {
        std::cout << q5.pop() << " ";
    }
    std::cout << std::endl;

    try{
        Queue bad;
        bad.push("1");
        bad.push("2");
    }
    catch(const std::exception& e){
        std::cerr << "Wystąpił błąd: " << e.what() << std::endl;
    }

    return 0;
}
