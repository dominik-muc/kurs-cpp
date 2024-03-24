#pragma once
#include <array>
#include <vector>
#include <iostream>

class Vector{
private:
    double x;
    double y;
public:
    Vector(double x, double y);
    //Vector(const Vector &ref);
};

class Point{
public:
    double x;
    double y;
public:
    Point(double x, double y);
    //Point(const Point &ref);
    //void Move(Vector v);
};

/* class Line{
private:
    double x;
    double y;
public:
    Line(double x, double y);
    Line(const Vector &ref);
}; */

template <int N>
class Figure{
protected:
    std::vector<Point> vertexes;
    std::vector<Point> sortedVertexes;
public:
    Figure(std::initializer_list<Point> args){
        for(Point p : args){
            vertexes.push_back(p);
        }
    }
    virtual void Show(){
        for(const Point &p : vertexes){
            std::cout << "(" << p.x << ", " << p.y << ")";
            if(&p != &vertexes.back()) std::cout << ", ";
        }
        std::cout << std::endl;
    }
    /* virtual Point GetCentroid();
    virtual float GetPerimeter();
    virtual float GetArea();
    virtual void Move(Vector v);
    virtual void Rotate(float angle);
    virtual void PointSymmetry(Point p);
    virtual void AxisSymmetry(Line axis); */
};
