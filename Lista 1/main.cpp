//Dominik Muc, 345952, Lista 1
#include <vector>
#include <string>
#include <iostream>

const std::vector <std::pair<int, std::string>> roman = {
 {1000, "M"},
 {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
 {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
 {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
 };

std::string toroman(int x){
    std::string s = "";
    int i = 0;
    while(x > 0){
        if(x >= roman[i].first){
            s += roman[i].second;
            x -= roman[i].first;
        }
        else i++;
    }
    return s;
}

int main(int argc, const char* argv[]){
    for(int i = 1; i < argc; i++){
        try{
            int t = std::stoi(argv[i]);
            
            if(t < 1 || t > 3999) throw std::invalid_argument("Wartość poza zakresem");
            std::cout << toroman(t) << std::endl;;
        }
        catch(std::exception &e){
            std::clog << "Nieprawidłowy argument: " << argv[i] << ". Powód błędu: " << e.what() << std::endl;
        }
    }
    
    return 0;
}