#include <algorithm>
#include <stdexcept> 
#include <cmath>

template <int N>
void Figure<N>::sort(){
    Point c = GetCentroid();
    std::sort(sortedVertices.begin(), sortedVertices.end(), [c](const Point& a, const Point& b) {
        return std::atan2(a.GetY() - c.GetY(), a.GetX() - c.GetX()) < std::atan2(b.GetY() - c.GetY(), b.GetX() - c.GetX());
    });
}

template <int N>
Figure<N>::Figure(std::initializer_list<Point> args){
    if(args.size() != N || N < 1) throw std::invalid_argument("Niepoprawna ilość wierzchołków");
    sort();
}

template <int N>
void Figure<N>::Show(){
    for(const Point &p : vertices){
        p.Show();
        if (&p != &vertices.back()) std::cout << ", ";
    }
    std::cout << std::endl;
}

template <int N>
Point Figure<N>::GetCentroid(){
    double sum_x = 0.0;
    double sum_y = 0.0;
    for(const Point &p : vertices){
        sum_x += p.GetX();
        sum_y += p.GetY();
    }
    return Point(sum_x / N, sum_y / N);
}

template <int N>
float Figure<N>::GetPerimeter(){
    double perimeter = 0.0;
    for(int i = 0; i < N; i++){
        int j = (i + 1) % N;
        perimeter += distance(vertices[i], vertices[j]);
    }
    return perimeter;
}

template <int N>
double Figure<N>::GetArea(){
    double area = 0.0;
    for(int i = 0; i < N; i++){
        int j = (i + 1) % N;
        area += vertices[i].GetX() * vertices[j].GetY() - vertices[j].GetX() * vertices[i].GetY();
    }
    return std::abs(area) / 2.0;
}

template <int N>
void Figure<N>::Move(Vector v){
    for(Point &p : vertices) p.Move(v);
    sort();
}

template <int N>
void Figure<N>::Rotate(Point pivot, double radians){
    for(Point &p : vertices) p.Rotate(pivot, radians);
    sort();
}

template <int N>
void Figure<N>::PointSymmetry(Point s){
    for(Point &p : vertices) p.PointSymmetry(s);
    sort();
}

template <int N>
void Figure<N>::AxisSymmetry(Line axis){
    for(Point &p : vertices) p.AxisSymmetry(axis);
    sort();
}