// Dominik Muc, 345952, Lista 8

#include <iomanip>

#include "lib.hpp"

#define PRECISION 2

int main() {
    std::cout << std::setprecision(PRECISION) << std::fixed;

    std::vector<Expression *> expressions;

    expressions.push_back(
        new Multiply(new Add(new Number(2), new Number(2)), new Number(2)));

    expressions.push_back(new Sub(
        new Pi(), new Add(new Number(2),
                          new Multiply(new Variable("x"), new Number(7)))));

    expressions.push_back(new Power(expressions.back(), expressions.back()));

    expressions.push_back(new Modulo(
        new Ln(new Add(new Variable("y"), new Euler())),
        new Abs(new Inverse(new Multiply(new Number(7), new Variable("z"))))));

    expressions.push_back(new Sinus(
        new Cosinus(new Exp(new Neg(new Log(new Number(2), new Phi()))))));

    expressions.push_back(new Divide(new Number(0), new Number(2)));

    Variable::bind(Variable("x"), 1);

    for (auto &it : expressions) {
        try {
            std::cout << "\nExpression: " << it->to_string() << std::endl;
            std::cout << "Value: " << it->evaluate() << std::endl;
        } catch (std::exception &e) {
            std::cerr << "Error occured: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;

    expressions.clear();

    expressions.push_back(
        new Divide(new Multiply(new Sub(new Variable("x"), new Number(1)),
                                new Variable("x")),
                   new Number(2)));

    expressions.push_back(
        new Divide(new Add(new Number(3), new Number(5)),
                   new Add(new Number(2),
                           new Multiply(new Variable("x"), new Number(7)))));

    expressions.push_back(new Sub(
        new Add(new Number(2), new Multiply(new Variable("x"), new Number(7))),
        new Add(new Multiply(new Variable("y"), new Number(3)),
                new Number(5))));

    expressions.push_back(new Divide(
        new Cosinus(
            new Multiply(new Add(new Variable("x"), new Number(1)), new Pi())),
        new Power(new Euler(), new Power(new Variable("x"), new Number(2)))));

    for (auto &it : expressions) {
        std::cout << "Expression: " << it->to_string() << std::endl;

        Variable::update(Variable("x"), 0);
        Variable::update(Variable("y"), 0);

        for (double i = 0.0; i < 1; i += 0.1) {
            Variable::update(Variable("x"), i);
            Variable::update(Variable("y"), i);

            std::cout << "Value for x, y = " << i << ": " << it->evaluate()
                      << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}