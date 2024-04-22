#pragma once
#include "color.hpp"
#include <string>
#include <cctype>

class NamedColor : virtual public Color{
protected:
    std::string name;
public:
    NamedColor() : Color() { name = ""; };
    NamedColor(unsigned short r, unsigned short g, unsigned short b, std::string s) : Color(r, g, b) {
        setName(s);
    };

    std::string getName() const { return name; }

    void setName(std::string s) { 
        for (char c : s) {
            if (!std::islower(c)) {
                throw std::invalid_argument("Name should consist only of lower-case letters");
            }
        }
        name = s;
    }
};