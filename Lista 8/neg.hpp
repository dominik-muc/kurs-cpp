// Dominik Muc, 345952, Lista 8

#pragma once
#include "binary.hpp"

class Neg : public Unary {
public:
    Neg(Expression *expr) : Unary(expr) {}
    std::string to_string() const override {
        std::string es1 = (this->e1)->to_string();
        if (typeid(*e1) == typeid(Add) || typeid(*e1) == typeid(Sub))
            es1 = "(" + es1 + ")";
        return "-" + es1;
    }
    double evaluate() const override { return -(e1->evaluate()); }
};