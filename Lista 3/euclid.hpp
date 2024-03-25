// Dominik Muc, 345952, Lista 3
#pragma once
#include <vector>
#include <stdexcept> 
#include <iostream>

const double EPSILON = 1e-6;

class Vector{
private:
    double x, y;
public:
    Vector(double x, double y);
    Vector(const Vector &ref);
    double GetX() const;
    double GetY() const;
};

class Point;

class Line{
public:
    double A, B, C;
    Line(double A, double B, double C) : A(A), B(B), C(C) { if(A == 0 && B == 0) throw std::invalid_argument("Niepoprawna prosta.");}
    Line(const Point& p1, const Point& p2);
};

class Point{
private:
    double x, y;
public:
    Point(double x, double y);
    Point(const Point &ref);
    double GetX() const;
    double GetY() const;
    void Show() const;
    void Move(Vector v);
    void Rotate(Point pivot, double radians);
    void PointSymmetry(Point s);
    void AxisSymmetry(Line axis);

    bool operator==(const Point &other){
        if(x == other.GetX() && y == other.GetY()) return true;
        return false;
    }
};

template <int N>
class Figure{
protected:
    std::vector<Point> vertices;
    std::vector<Point> sortedVertices;
    void sort();

public:
    Figure(std::initializer_list<Point> args);
    virtual std::vector<Point> GetVertices();
    virtual void Show();
    virtual Point GetCentroid();
    virtual float GetPerimeter();
    virtual double GetArea();
    virtual void Move(Vector v);
    virtual void Rotate(Point pivot, double radians);
    virtual void PointSymmetry(Point s);
    virtual void AxisSymmetry(Line axis);
};

#include "euclid.tpp"

class Segment : public Figure<2>{
public:
    Segment(Point a, Point b);
    bool Contains(Point a);
};

class Triangle : public Figure<3>{
public:
    Triangle(Point a, Point b, Point c);
    bool Contains(Point a);
};


bool Parallel(Segment a, Segment b);
bool Perpendicular(Segment a, Segment b);
bool TriangleContains(Triangle a, Triangle b);
bool TriangleDisjoint(Triangle a, Triangle b);