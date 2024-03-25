// Dominik Muc, 345952, Lista 3
#include <iostream>
#include "euclid.hpp"

int main() {
    try {
        Point p1(0, 0);
        Point p2(4, 0);
        Point p3(4, 3);
        Point p4(0, 3);
        
        Vector v(1, 1);

        Segment segment(p1, p2);
        std::cout << "Odcinek: ";
        segment.Show();

        Triangle triangle(p1, p3, p4);
        std::cout << "Trójkąt: ";
        triangle.Show();

        std::cout << "Odległość p1 do p2: " << Distance(p1, p2) << std::endl;

        Segment segment2(p2, p3);
        std::cout << "Czy odcinki są równoległe? " << (Parallel(segment, segment2) ? "Tak" : "Nie") << std::endl;
        std::cout << "Czy odcinki są prostopadłe? " << (Perpendicular(segment, segment2) ? "Tak" : "Nie") << std::endl;

        Triangle triangle2(p1, Point(2, 1), Point(0, 2));
        std::cout << "Czy trójkąt zawiera się w drugim trójkącie? " << (TriangleContains(triangle, triangle2) ? "Tak" : "Nie") << std::endl;

        std::cout << "Czy trójkąty są rozłączne? " << (TriangleDisjoint(triangle, triangle2) ? "Tak" : "Nie") << std::endl;

        std::cout << "Przesunięcie trójkąta o wektor v: ";
        triangle.Move(v);
        triangle.Show();

        std::cout << "Obrót trójkąta wokół p1 o 90 stopni: ";
        triangle.Rotate(p1, M_PI / 2);
        triangle.Show();

        Line axis(p1, p3);
        std::cout << "Symetria punktu p2 względem linii p1-p3: ";
        p2.AxisSymmetry(axis);
        p2.Show();

        std::cout << "\nSymetria odcinka względem punktu p1: ";
        segment.PointSymmetry(p1);
        segment.Show();

        std::cout << "Symetria trójkąta względem linii p1-p3: ";
        triangle.AxisSymmetry(axis);
        triangle.Show();

        Triangle t(Point(0, 0), Point(0, 0), Point(1, 2));

    } catch (const std::exception& e) {
        std::cerr << "Wyjątek: " << e.what() << std::endl;
    }

    return 0;
}
