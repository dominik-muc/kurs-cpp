#include "euclid.hpp"

int main(){
    Figure<3> f = Figure<3>({Point{1.0, 2.0}, Point{3.0, 4.0}, Point{5.0, 6.0}});
    f.Show();
    return 0;
}