#pragma once
#include "named_color.hpp"
#include "transparent_color.hpp"

class TNColor : public TransparentColor, public NamedColor{
public:
    TNColor() : Color() { alpha = 0; name = ""; }
    TNColor(unsigned short r, unsigned short g, unsigned short b, unsigned short a, std::string s){
        setAlpha(a);
        setName(s);
    }
};