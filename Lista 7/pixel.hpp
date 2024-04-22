#pragma once
#include <stdexcept>

enum Edge {
    LEFT,
    TOP,
    RIGHT,
    BOTTOM
};

class Pixel {
protected:
    int x, y;
public:
    static const int height = 1080;
    static const int width = 1920;

    Pixel(int x, int y);

    void setX(int x);
    void setY(int y);

    int getX() const;
    int getY() const;

    static float distanceBetween(Pixel* a, Pixel* b);
    static float distanceBetween(Pixel& a, Pixel& b);
    int distanceTo(Edge e) const;
};
