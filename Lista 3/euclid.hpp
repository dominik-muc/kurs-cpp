#pragma once
#include <vector>
#include <stdexcept> 
#include <iostream>

class Vector{
private:
    double x, y;
public:
    Vector(double x, double y);
    Vector(const Vector &ref);
    double GetX() const;
    double GetY() const;
};

class Line{
public:
    double A, B, C;
    Line(double A, double B, double C) : A(A), B(B), C(C) { if(A == 0 && B == 0) throw std::invalid_argument("Niepoprawna prosta.");}
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

double distance(const Point& p1, const Point& p2);

template <int N>
class Figure{
protected:
    std::vector<Point> vertices;
    std::vector<Point> sortedVertices;
    void sort();

public:
    Figure(std::initializer_list<Point> args);
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

class Segment : Figure<2>{
    Segment(Point a, Point b);
    bool Contains(Point a);
};

class Triangle : Figure<3>{
    Triangle(Point a, Point b, Point c);
    bool Contains(Point a);
};