#pragma once
#include "pixel.hpp"
#include "color.hpp"

struct Vector{ int x, y; };

class ColoredPixel : public Pixel{
protected:
    Color color;
public:
    ColoredPixel(int x, int y, Color color) : Pixel(x, y) { setColor(color); }

    void setColor(Color color){ this->color = color; }
    Color getColor() const { return color; }

    void move(Vector v){
        setX(x + v.x);
        setY(y + v.y);
    }
};