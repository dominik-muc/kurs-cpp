// Dominik Muc, 345952, Lista 8

#pragma once
#include "expression.hpp"
#include <stdexcept>
#include <map>

class Variable : public Expression {
private:
    static std::map<std::string, double> environment;
    std::string identifier;
public:
    Variable(std::string identifier) : identifier(identifier) {}
    std::string to_string() const override { return this->identifier; }
    double evaluate() const override { 
        auto it = environment.find(identifier);
        if(it == environment.end()) throw std::runtime_error("Unbound value: " + identifier);
        return it->second;
    }
    static void bind(Variable var, double value){
        if(environment.find(var.identifier) != environment.end()) throw std::runtime_error("Value already bound. You should try using update().");
        environment[var.identifier] = value;
    }
    static void update(Variable var, double value){
        // If the value isn't bound, we do it straight away.
        environment[var.identifier] = value;
    }
    static void unbind(Variable var){
        // We doesn't care wheter variable is bound or not
        environment.erase(var.identifier);
    }
};

std::map<std::string, double> Variable::environment = {};