// Dominik Muc, 345952, Lista 8

#pragma once
#include "binary.hpp"

class Inverse : public Unary {
public:
    Inverse(Expression *expr) : Unary(expr) {}
    std::string to_string() const override {
        std::string es1 = (this->e1)->to_string();
        if (typeid(*e1) == typeid(Add) || typeid(*e1) == typeid(Sub))
            es1 = "(" + es1 + ")";
        return "1/" + es1;
    }
    double evaluate() const override { return 1 / (e1->evaluate()); }
};