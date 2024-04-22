#pragma once
#include <stdexcept>

class Color{
protected:
    unsigned short r, g, b;
public:
    Color();
    Color(unsigned short r, unsigned short g, unsigned short b);
    
    unsigned short getRed() const;
    unsigned short getGreen() const;
    unsigned short getBlue() const;
    void setRed(unsigned short r);
    void setGreen(unsigned short g);
    void setBlue(unsigned short b);

    void brighten();
    void darken();

    static Color mix(const Color& a, const Color& b);
};