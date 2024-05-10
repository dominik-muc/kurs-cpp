// Dominik Muc, 345952, Lista 8

#pragma once
#include <string>
#include <typeinfo>

class Expression {
public:
    virtual std::string to_string() const = 0;
    virtual double evaluate() const = 0;

    Expression() = default;
    virtual ~Expression() = default;

    Expression(const Expression&) = delete;
    Expression& operator=(const Expression&) = delete;

    Expression(Expression&&) = delete;
    Expression& operator=(Expression&&) = delete;
};