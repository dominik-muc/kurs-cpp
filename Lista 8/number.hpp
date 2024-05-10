// Dominik Muc, 345952, Lista 8

#pragma once
#include <sstream>

#include "expression.hpp"

class Number : public Expression {
private:
    double value;

public:
    Number(double value) { this->value = value; }
    double evaluate() const override { return this->value; }
    std::string to_string() const override {
        std::stringstream s;
        s << (this->value);
        return s.str();
    }
};