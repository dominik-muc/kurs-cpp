#pragma once
#include "color.hpp"


class TransparentColor : virtual public Color{
protected:
    unsigned short alpha;
public:
    TransparentColor() : Color() { alpha = 0; }
    TransparentColor(unsigned short r, unsigned short g, unsigned short b, unsigned short a) : Color(r, g, b) {
        setAlpha(a);
    }

    unsigned short getAlpha() const { return alpha; }

    void setAlpha(unsigned short a) { 
        if(a > 255) throw std::invalid_argument("Alpha cannot excede 255");
        alpha = a;
    }
};