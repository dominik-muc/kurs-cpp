// Dominik Muc, 345952, Lista 4

#pragma once
#include <stdexcept>

class Number{
protected:
    double* history = new double[MAX_HISTORY];
    int index;
    int undoable;
public:
    const static int MAX_HISTORY = 3;

    Number(double value);
    Number() : Number(0.0) {};
    Number(const Number& other);
    Number(Number&& ref);
    ~Number();

    void Set(double value);
    double Get() const;
    void Undo();

    Number& operator =(Number&& other){
        if(this != &other){
            Set(other.Get());

            other.index = 0;
            other.undoable = 0;
            other.history = new double[MAX_HISTORY];
        }
        return *this;
    }

    Number& operator =(const Number& ref){
        Set(ref.Get());
        return *this;
    }
};