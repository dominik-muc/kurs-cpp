// Dominik Muc, 345952, Lista 6

#include "polynomial.hpp"
#include <cmath>
#define E 0.00001

Polynomial::Polynomial(int degree, double factor){
    if(degree < 0) throw std::invalid_argument("Invalid degree.");
    this->degree = degree;
    this->factors = new double[degree + 1] {0.0};
    this->factors[0] = factor;
}

Polynomial::Polynomial(int degree, const double factors[]){
    if(degree < 0) throw std::invalid_argument("Invalid degree.");
    this->degree = degree;
    this->factors = new double[this->degree + 1] {0.0};
    for(int i = 0; i <= this->degree; i++){
        this->factors[i] = factors[i];
    }
}

Polynomial::Polynomial(std::initializer_list<double> factors){
    this->degree = factors.size();
    this->factors = new double[this->degree + 1] {0.0};
    int i = 0;
    for (auto factor : factors) {
        this->factors[i++] = factor;
    }
}

Polynomial::Polynomial(const Polynomial &u){
    this->degree = u.degree;
    this->factors = new double[this->degree + 1];
    for(int i = 0; i <= this->degree; i++){
        this->factors[i] = u.factors[i];
    }
}

Polynomial::Polynomial(Polynomial &&u){
    this->degree = u.degree;
    this->factors = new double[this->degree + 1];
    for(int i = 0; i <= this->degree; i++){
        this->factors[i] = u.factors[i];
    }
    u.degree = 0;
    u.factors = nullptr;
}

Polynomial& Polynomial::operator=(const Polynomial &u){
    if(this == &u) return *this;
    this->degree = u.degree;
    this->factors = new double[this->degree + 1];
    for(int i = 0; i <= this->degree; i++){
        this->factors[i] = u.factors[i];
    }
    return *this;
}

Polynomial& Polynomial::operator=(Polynomial &&u){
    if(this == &u) return *this;
    this->degree = u.degree;
    this->factors = new double[this->degree + 1];
    for(int i = 0; i <= this->degree; i++){
        this->factors[i] = u.factors[i];
    }
    u.degree = 0;
    u.factors = nullptr;
    return *this;
}

Polynomial::~Polynomial(){
    delete[] factors;
}

std::istream& operator>>(std::istream &in, Polynomial &u){
    delete[] u.factors;
    in >> u.degree;
    u.factors = new double[u.degree + 1];
    for(int i = u.degree; i >= 0; i--){
        in >> u.factors[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream &out, const Polynomial &u){
    for(int i = u.degree; i >= 2; i--){
        if(fabs(u.factors[i]) > E){
            if(u.factors[i] == -1) out << "-x^" << i << " + ";
            else if(u.factors[i] == 1) out << "x^" << i << " + ";
            else out << u.factors[i] << "x^" << i << " + ";
        }
    }
    if(u.degree > 0 && fabs(u.factors[1]) > E) out << u.factors[1] << "x + ";
    out << u.factors[0];
    return out;
}

Polynomial operator+(const Polynomial &u, const Polynomial &v){
    Polynomial p(u);
    p += v;
    return p;
}

Polynomial operator-(const Polynomial &u, const Polynomial &v){
    Polynomial p(u);
    p -= v;
    return p;
}

Polynomial operator*(const Polynomial &u, const Polynomial &v){
    Polynomial p(u);
    p *= v;
    return p;
}

Polynomial operator*(const Polynomial &u, double c){
    Polynomial p(u);
    p *= c;
    return p;
}

Polynomial& Polynomial::operator+=(const Polynomial &v){
    if(v.degree > this->degree){
        double* temp = new double[this->degree + 1]{0};
        for(int i = 0; i <= this->degree; i++){
            temp[i] = this->factors[i];
        }

        this->degree = v.degree;
        delete[] this->factors;
        this->factors = new double[v.degree + 1]{0};
        for(int i = 0; i <= this->degree; i++){
            this->factors[i] = temp[i];
        }
    }

    for(int i = 0; i <= v.degree; i++){
        this->factors[i] += v.factors[i];
    }
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial &v){
    if(v.degree > this->degree){
        double* temp = new double[this->degree + 1]{0};
        for(int i = 0; i <= this->degree; i++){
            temp[i] = this->factors[i];
        }

        this->degree = v.degree;
        delete[] this->factors;
        this->factors = new double[v.degree + 1]{0};
        for(int i = 0; i <= this->degree; i++){
            this->factors[i] = temp[i];
        }
    }

    for(int i = 0; i <= v.degree; i++){
        this->factors[i] -= v.factors[i];
    }
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial &v){
    int new_degree = this->degree + v.degree;
    double* temp = new double[new_degree + 1]{0};

    for(int i = 0; i <= this->degree; i++){
        for(int j = 0; j <= v.degree; j++){
            temp[i + j] += this->factors[i] * v.factors[j];
        }
    }

    delete[] this->factors;
    this->factors = temp;
    this->degree = new_degree;

    return *this;
}

Polynomial& Polynomial::operator*=(double c){
    for(int i = 0; i <= degree; i++){
        factors[i] *= c;
    }
    return *this;
}

double Polynomial::operator()(double x) const{
    double value = factors[0];
    for(int i = 0; i < degree; i++){
        value = (value * x) + factors[i + 1];
    }
    return value;
}

double Polynomial::operator[](int i) const{
    if(i > degree || i < 0) throw std::invalid_argument("Invalid factor.");
    return factors[i];
}

double& Polynomial::operator[](int i){
    if(i > degree || i < 0) throw std::invalid_argument("Invalid factor.");
    return factors[i];
}
