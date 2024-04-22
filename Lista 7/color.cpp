#include "color.hpp"

Color::Color() : r(0), g(0), b(0) {}

Color::Color(unsigned short r, unsigned short g, unsigned short b) : r(r), g(g), b(b) {}

unsigned short Color::getRed() const { return r; }
unsigned short Color::getGreen() const { return g; }
unsigned short Color::getBlue() const { return b; }

void Color::setRed(unsigned short r) { this->r = r; }
void Color::setGreen(unsigned short g) { this->g = g; }
void Color::setBlue(unsigned short b) { this->b = b; }

void Color::brighten() {
    r = (r * 1.1 > 255) ? 255 : static_cast<unsigned short>(r * 1.1);
    g = (g * 1.1 > 255) ? 255 : static_cast<unsigned short>(g * 1.1);
    b = (b * 1.1 > 255) ? 255 : static_cast<unsigned short>(b * 1.1);
}

void Color::darken() {
    r = (r * 0.9 < 0) ? 0 : static_cast<unsigned short>(r * 0.9);
    g = (g * 0.9 < 0) ? 0 : static_cast<unsigned short>(g * 0.9);
    b = (b * 0.9 < 0) ? 0 : static_cast<unsigned short>(b * 0.9);
}

Color Color::mix(const Color& a, const Color& b){
    return Color(
        (a.r + b.r) / 2,
        (a.g + b.g) / 2,
        (a.b + b.b) / 2
    );
}
