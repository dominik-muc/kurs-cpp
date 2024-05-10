// Dominik Muc, 345952, Lista 8

#include "binary.hpp"

Binary::Binary(Expression* e1, Expression* e2) : Unary(e1), e2(e2) {}

Add::Add(Expression* e1, Expression* e2) : Binary(e1, e2) {}

std::string Add::to_string() const {
    return (this->e1)->to_string() + " + " + (this->e2)->to_string();
}

double Add::evaluate() const {
    return e1->evaluate() + e2->evaluate();
}

Sub::Sub(Expression* e1, Expression* e2) : Binary(e1, e2) {}

std::string Sub::to_string() const {
    std::string es2 = (this->e2)->to_string();
    if (typeid(*e2) == typeid(Add) || typeid(*e2) == typeid(Sub)) es2 = "(" + es2 + ")";
    return (this->e1)->to_string() + " - " + es2;
}

double Sub::evaluate() const {
    return e1->evaluate() - e2->evaluate();
}

Multiply::Multiply(Expression* e1, Expression* e2) : Binary(e1, e2) {}

std::string Multiply::to_string() const {
    std::string es1 = (this->e1)->to_string();
    std::string es2 = (this->e2)->to_string();
    if (typeid(*e1) == typeid(Add) || typeid(*e1) == typeid(Sub)) es1 = "(" + es1 + ")";
    if (typeid(*e2) == typeid(Add) || typeid(*e2) == typeid(Sub)) es2 = "(" + es2 + ")";
    return es1 + " * " + es2;
}

double Multiply::evaluate() const {
    return e1->evaluate() * e2->evaluate();
}

Divide::Divide(Expression* e1, Expression* e2) : Binary(e1, e2) {}

std::string Divide::to_string() const {
    std::string es1 = (this->e1)->to_string();
    std::string es2 = (this->e2)->to_string();
    if (typeid(*e1) == typeid(Add) || typeid(*e1) == typeid(Sub) || typeid(*e1) == typeid(Multiply)) es1 = "(" + es1 + ")";
    if (typeid(*e2) == typeid(Add) || typeid(*e2) == typeid(Sub) || typeid(*e1) == typeid(Multiply) || typeid(*e1) == typeid(Divide)) es2 = "(" + es2 + ")";
    return es1 + " / " + es2;
}

double Divide::evaluate() const {
    return e1->evaluate() / e2->evaluate();
}

Log::Log(Expression* e1, Expression* e2) : Binary(e1, e2) {}

std::string Log::to_string() const {
    std::string es1 = (this->e1)->to_string();
    std::string es2 = (this->e2)->to_string();
    return "log(" + es1 + ")(" + es2 + ")";
}

double Log::evaluate() const {
    return log(e2->evaluate()) / log(e1->evaluate());
}

Modulo::Modulo(Expression* e1, Expression* e2) : Binary(e1, e2) {}

std::string Modulo::to_string() const {
    std::string es1 = (this->e1)->to_string();
    std::string es2 = (this->e2)->to_string();
    if (typeid(*e1) == typeid(Add) || typeid(*e1) == typeid(Sub) || typeid(*e1) == typeid(Multiply) || typeid(*e1) == typeid(Divide) || typeid(*e1) == typeid(Log) || typeid(*e1) == typeid(Modulo)) {
        es1 = "(" + es1 + ")";
    }
    if (typeid(*e2) == typeid(Add) || typeid(*e2) == typeid(Sub) || typeid(*e2) == typeid(Multiply) || typeid(*e2) == typeid(Divide) || typeid(*e2) == typeid(Log) || typeid(*e2) == typeid(Modulo)) {
        es2 = "(" + es2 + ")";
    }
    return es1 + " % " + es2;
}

double Modulo::evaluate() const {
    return std::fmod(e1->evaluate(), e2->evaluate());
}

Power::Power(Expression* e1, Expression* e2) : Binary(e1, e2) {}

std::string Power::to_string() const {
    std::string es1 = (this->e1)->to_string();
    std::string es2 = (this->e2)->to_string();
    if (typeid(*e1) == typeid(Add) || typeid(*e1) == typeid(Sub) || typeid(*e1) == typeid(Multiply) || typeid(*e1) == typeid(Divide) || typeid(*e1) == typeid(Power) || typeid(*e1) == typeid(Log) || typeid(*e1) == typeid(Modulo)) {
        es1 = "(" + es1 + ")";
    }
    if (typeid(*e2) == typeid(Add) || typeid(*e2) == typeid(Sub) || typeid(*e2) == typeid(Multiply) || typeid(*e2) == typeid(Divide) || typeid(*e2) == typeid(Power) || typeid(*e2) == typeid(Log) || typeid(*e2) == typeid(Modulo)) {
        es2 = "(" + es2 + ")";
    }
    return es1 + " ^ " + es2;
}

double Power::evaluate() const {
    return std::pow(e1->evaluate(), e2->evaluate());
}

