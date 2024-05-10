// Dominik Muc, 345952, Lista 8

#pragma once
#include "unary.hpp"

class Binary : public Unary {
protected:
    Expression* e2;
    Binary(Expression* e1, Expression* e2);
};

class Add : public Binary {
public:
    Add(Expression* e1, Expression* e2);
    std::string to_string() const override;
    double evaluate() const override;
};

class Sub : public Binary {
public:
    Sub(Expression* e1, Expression* e2);
    std::string to_string() const override;
    double evaluate() const override;
};

class Multiply : public Binary {
public:
    Multiply(Expression* e1, Expression* e2);
    std::string to_string() const override;
    double evaluate() const override;
};

class Divide : public Binary {
public:
    Divide(Expression* e1, Expression* e2);
    std::string to_string() const override;
    double evaluate() const override;
};

class Log : public Binary {
public:
    Log(Expression* e1, Expression* e2);
    std::string to_string() const override;
    double evaluate() const override;
};

class Modulo : public Binary {
public:
    Modulo(Expression* e1, Expression* e2);
    std::string to_string() const override;
    double evaluate() const override;
};

class Power : public Binary {
public:
    Power(Expression* e1, Expression* e2);
    std::string to_string() const override;
    double evaluate() const override;
};
