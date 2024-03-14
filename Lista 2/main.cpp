//Dominik Muc, 345952, Lista 2
//Kompilator: g++ (GCC) 13.2.1 20230801
#include <vector>
#include <iostream>
#include <math.h>

std::vector<int64_t> rozklad(int64_t n){
    std::vector<int64_t> v;
    while(n % 2 == 0 && n != 0){
        n /= 2;
        v.push_back(2);
    }
    n *= n < 0 ? -1 : 1;
    for(int64_t i = 3; i <= std::sqrt(n); i += 2){
        while(n % i == 0){
            n /= i;
            v.push_back(i);
        }
    }
    if(n > 2) v.push_back(n);
    return v;
}

int main(int argc, const char* argv[]){
    if(argc < 2){
        std::cerr << "Program jako argumenty wejścia przyjmuje liczby z zakresu int64_t i dla każdej z nich wypisuje jej rozkład na czynniki pierwsze." << std::endl;
        return 0;
    }
    for(int i = 1; i < argc; i++){
        try{
            int64_t a = std::stoll(argv[i]);
            std::cout << a << " = " << (a < 0 ? a == -1 ? "-1" : "-1 * " : (a == 0 ? "0" : a == 1 ? "1" : ""));
            std::vector<int64_t> v = rozklad(a);
            if(v.size() > 0) std::cout << v[0];
            for(int i = 1; i < v.size(); i++) std::cout << " * " << v[i];
            std::cout << '\n';
        }
        catch(std::exception &e){
            std::clog << "Niepoprawny argument: " << argv[i] << " Powód błędu: " << e.what() << std::endl;
        }
    }
}