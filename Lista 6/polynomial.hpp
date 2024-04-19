// Dominik Muc, 345952, Lista 6

#include <iostream>

class Polynomial {
private:
    int degree; // stopień wielomianu
    double *factors; // współczynniki wielomianu
public:
    Polynomial (int degree = 0, double factor = 1.0); // konstruktor jednomianu
    Polynomial (int degree, const double factors[]); // konstruktor wielomianu
    Polynomial (std::initializer_list<double> factors); // lista współczynników
    Polynomial (const Polynomial &u); // konstruktor kopiujący
    Polynomial (Polynomial &&u); // konstruktor przenoszący
    Polynomial& operator = (const Polynomial &u); // przypisanie kopiujące
    Polynomial& operator = (Polynomial &&u); // przypisanie przenoszące
    ~Polynomial (); // destruktor
    friend std::istream& operator >> (std::istream &in, Polynomial &u);
    friend std::ostream& operator << (std::ostream &out, const Polynomial &u);
    friend Polynomial operator + (const Polynomial &u, const Polynomial &v);
    friend Polynomial operator - (const Polynomial &u, const Polynomial &v);
    friend Polynomial operator * (const Polynomial &u, const Polynomial &v);
    friend Polynomial operator * (const Polynomial &u, double c);
    Polynomial& operator += (const Polynomial &v);
    Polynomial& operator -= (const Polynomial &v);
    Polynomial& operator *= (const Polynomial &v);
    Polynomial& operator *= (double c);
    double operator () (double x) const; // wartość wielomianu dla x
    double operator [] (int i) const; // do odczytu współczynnika
    double& operator [] (int i); // do zapisu współczynnika
};