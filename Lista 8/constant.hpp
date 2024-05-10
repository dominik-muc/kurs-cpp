// Dominik Muc, 345952, Lista 8

#pragma once
#include "expression.hpp"

class Constant : public Expression {
private:
    const std::string identifier;
    const double value;
public:
    Constant(const std::string identifier, const double value) : identifier(identifier), value(value) {}
    std::string to_string() const override { return this->identifier; }
    double evaluate() const override { return this->value; }
};

class Pi : public Constant{
public:
    Pi() : Constant("π", 3.14159265359) {}
};

class Phi : public Constant{
public:
    Phi() : Constant("ɸ", 1.61803398875) {}
};

class Euler : public Constant{
public:
    Euler() : Constant("e", 2.71828182846) {}
};