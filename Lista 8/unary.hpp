// Dominik Muc, 345952, Lista 8

#pragma once
#include <cmath>

#include "expression.hpp"

class Unary : public Expression {
protected:
    Expression *e1;
    Unary(Expression *expr) : e1(expr) {}
};

class Sinus : public Unary {
public:
    Sinus(Expression *expr) : Unary(expr) {}
    std::string to_string() const override {
        return "sin(" + (this->e1)->to_string() + ")";
    }
    double evaluate() const override { return sin(e1->evaluate()); }
};

class Cosinus : public Unary {
public:
    Cosinus(Expression *expr) : Unary(expr) {}
    std::string to_string() const override {
        return "cos(" + (this->e1)->to_string() + ")";
    }
    double evaluate() const override { return cos(e1->evaluate()); }
};

class Exp : public Unary {
public:
    Exp(Expression *expr) : Unary(expr) {}
    std::string to_string() const override {
        return "exp(" + (this->e1)->to_string() + ")";
    }
    double evaluate() const override { return exp(e1->evaluate()); }
};

class Ln : public Unary {
public:
    Ln(Expression *expr) : Unary(expr) {}
    std::string to_string() const override {
        return "ln(" + (this->e1)->to_string() + ")";
    }
    double evaluate() const override { return log(e1->evaluate()); }
};

class Abs : public Unary {
public:
    Abs(Expression *expr) : Unary(expr) {}
    std::string to_string() const override {
        return "|" + (this->e1)->to_string() + "|";
    }
    double evaluate() const override { return fabs(e1->evaluate()); }
};
