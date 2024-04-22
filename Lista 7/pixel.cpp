#include "pixel.hpp"
#include <cmath>

Pixel::Pixel(int x, int y){
    setX(x);
    setY(y);
}

void Pixel::setX(int x){
    if (x < 0 || x > width) throw std::invalid_argument("Pixel x-coordinate out of screen bounds");
    this->x = x;
}

void Pixel::setY(int y){
    if (y < 0 || y > height) throw std::invalid_argument("Pixel y-coordinate out of screen bounds");
    this->y = y;
}

int Pixel::getX() const {
    return x;
}

int Pixel::getY() const {
    return y;
}

float Pixel::distanceBetween(Pixel* a, Pixel* b){
    return std::sqrt(std::pow(a->x - b->x, 2) + std::pow(a->y - b->y, 2));
}

float Pixel::distanceBetween(Pixel& a, Pixel& b){
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

int Pixel::distanceTo(Edge e) const {
    switch (e){
        case LEFT:
            return x;
        case TOP:
            return y;
        case RIGHT:
            return width - x;
        case BOTTOM:
            return height - y;
        default:
            throw std::invalid_argument("Unknown edge");
    }
}
