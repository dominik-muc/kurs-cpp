#include "euclid.hpp"

// Global methods

double distance(const Point& p1, const Point& p2){
    return std::sqrt((p2.GetX() - p1.GetX()) * (p2.GetX() - p1.GetX()) + (p2.GetY() - p1.GetY()) * (p2.GetY() - p1.GetY()));
}

// Vector

Vector::Vector(double x, double y) : x(x), y(y) {}

Vector::Vector(const Vector &ref){
    x = ref.GetX();
    y = ref.GetY();
}

double Vector::GetX() const { return x; }

double Vector::GetY() const { return y; }

// Point

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Point &ref){
    x = ref.GetX();
    y = ref.GetY();
}

double Point::GetX() const { return x; }

double Point::GetY() const { return y; }

void Point::Show() const { std::cout << "(" << x << ", " << y << ")"; }

void Point::Move(Vector v){
    x += v.GetX();
    y += v.GetY();
}

void Point::Rotate(Point pivot, double radians){
    double dx = x - pivot.GetX();
    double dy = y - pivot.GetY();

    double xRotated = dx * cos(radians) - dy * sin(radians);
    double yRotated = dx * sin(radians) + dy * cos(radians);

    x = xRotated + pivot.GetX();
    y = yRotated + pivot.GetY();
}

void Point::PointSymmetry(Point s){
    x = 2 * s.GetX() - x;
    y = 2 * s.GetY() - y;
}

void Point::AxisSymmetry(Line axis){
    double D = -axis.A * y - axis.B * x;
    
    double det = axis.A * axis.A + axis.B * axis.B;
    double x_q = (-axis.A * D - axis.B * axis.C) / det;
    double y_q = (-axis.B * D + axis.A * axis.C) / det;
    
    x = 2 * x_q - x;
    y = 2 * y_q - y;
}

// Segment

Segment::Segment(Point a, Point b) : Figure<2>({a, b}){
    if(a == b) throw std::invalid_argument("Punkty nie mogą być takie same.");  
    vertices.push_back(a); 
    vertices.push_back(b);
    sort();
}

// Triangle

Triangle::Triangle(Point a, Point b, Point c) : Figure<3>({a, b, c}){
    if(a.GetX() * (b.GetY() - c.GetY()) + b.GetX() * (c.GetY() - a.GetY()) + c.GetX() * (a.GetY() - b.GetY()) == 0) throw std::invalid_argument("Niepoprawny trójkąt.");
    vertices.push_back(a); 
    vertices.push_back(b);
    vertices.push_back(c);
    sort();
}