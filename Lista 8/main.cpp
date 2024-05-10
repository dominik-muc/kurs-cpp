// Dominik Muc, 345952, Lista 8

#include "lib.hpp"

int main(){
    std::vector<Expression*> expressions;

    expressions.push_back(
        new Multiply(
            new Add(
                new Number(2),
                new Number(2)
            ),
            new Number(2)
        )
    );

    expressions.push_back(
        new Sub(
            new Pi(),
            new Add(
                new Number(2),
                new Multiply(
                    new Variable("x"),
                    new Number(7)
                )
            )    
        )
    );

    expressions.push_back(
        new Power(
            expressions.back(),
            expressions.back()
        )
    );
    
    expressions.push_back(
        new Modulo(
            new Ln(
                new Add(
                    new Variable("y"),
                    new Euler()
                )
            ),
            new Abs(
                new Inverse(
                    new Multiply(
                        new Number(7),
                        new Variable("z")
                    )
                )
            )
        )
    );

    expressions.push_back(
        new Sinus(
            new Cosinus(
                new Exp(
                    new Neg(
                        new Log(
                            new Number(2),
                            new Phi()
                        )
                    )
                )
            )
        )
    );

    Variable::bind(Variable("x"), 1);

    for(auto& it : expressions){
        try{
            std::cout << "\nExpression: " << it->to_string() << std::endl;
            std::cout << "Value: " << it->evaluate() << std::endl;
        }
        catch (std::exception& e){
            std::cerr << "Error occured: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;

    return 0;
}