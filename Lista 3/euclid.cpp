// Dominik Muc, 345952, Lista 3
#include "euclid.hpp"

// Global methods

double Distance(const Point& p1, const Point& p2){
    return std::sqrt((p2.GetX() - p1.GetX()) * (p2.GetX() - p1.GetX()) + (p2.GetY() - p1.GetY()) * (p2.GetY() - p1.GetY()));
}

bool Parallel(Segment a, Segment b){
    Line l1(a.GetVertices()[0], a.GetVertices()[1]);
    Line l2(b.GetVertices()[0], b.GetVertices()[1]);
    return l1.A/l1.B == l2.A/l2.B;
}

bool Perpendicular(Segment a, Segment b){
    Line l1(a.GetVertices()[0], a.GetVertices()[1]);
    Line l2(b.GetVertices()[0], b.GetVertices()[1]);
    return l1.A * l2.A + l1.B * l2.B == 0;
}

bool TriangleContains(Triangle a, Triangle b){
    return a.Contains(b.GetVertices()[0]) && a.Contains(b.GetVertices()[1]) && a.Contains(b.GetVertices()[2]);
}

bool TriangleDisjoint(Triangle a, Triangle b){
    return !a.Contains(b.GetVertices()[0]) && !a.Contains(b.GetVertices()[1]) && !a.Contains(b.GetVertices()[2]) &&
           !b.Contains(a.GetVertices()[0]) && !b.Contains(a.GetVertices()[1]) && !b.Contains(a.GetVertices()[2]);
}

// Vector

Vector::Vector(double x, double y) : x(x), y(y) {}

Vector::Vector(const Vector &ref){
    x = ref.GetX();
    y = ref.GetY();
}

double Vector::GetX() const { return x; }

double Vector::GetY() const { return y; }

// Line

Line::Line(const Point& p1, const Point& p2){
    A = p2.GetY() - p1.GetY();
    B = p1.GetX() - p2.GetX();
    C = p1.GetX() * p2.GetY() - p2.GetX() * p1.GetY();
    if(A == 0 && B == 0) throw std::invalid_argument("Niepoprawna prosta.");
}

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

bool Segment::Contains(Point a){
    return Distance(vertices[0], vertices[1]) == (Distance(vertices[0], a) + Distance(vertices[1], a));
}

// Triangle

Triangle::Triangle(Point a, Point b, Point c) : Figure<3>({a, b, c}){
    if(std::abs(a.GetX() * (b.GetY() - c.GetY()) + b.GetX() * (c.GetY() - a.GetY()) + c.GetX() * (a.GetY() - b.GetY())) < EPSILON) throw std::invalid_argument("Niepoprawny trójkąt.");
    vertices.push_back(a); 
    vertices.push_back(b);
    vertices.push_back(c);
    sort();
}

bool Triangle::Contains(Point a){
    auto area = [](const Point& p1, const Point& p2, const Point& p3) {
        return std::abs(p1.GetX() * (p2.GetY() - p3.GetY()) + p2.GetX() * (p3.GetY() - p1.GetY()) + p3.GetX() * (p1.GetY() - p2.GetY())) / 2.0;
    };

    double mainArea = area(vertices[0], vertices[1], vertices[2]);

    double area1 = area(a, vertices[1], vertices[2]);
    double area2 = area(vertices[0], a, vertices[2]);
    double area3 = area(vertices[0], vertices[1], a);

    return std::abs(mainArea - (area1 + area2 + area3)) < EPSILON;
}