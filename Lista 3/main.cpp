#include "euclid.hpp"

int main(){
    Figure<3> f({Point(-2, 0), Point(-1, 0), Point(-2, 1)});
    f.Show();
    std::cout << f.GetArea() << std::endl;
    std::cout << f.GetPerimeter() << std::endl;
    f.Move(Vector(2, 0));
    f.Show();
    std::cout << f.GetArea() << std::endl;
    std::cout << f.GetPerimeter() << std::endl;
    Point p(1, 2);
    p.Show();
    Segment s();
    return 0;
}