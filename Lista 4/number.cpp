// Dominik Muc, 345952, Lista 4

#include "number.hpp"
#include <stdexcept>

Number::Number(double value){
    index = 0;
    undoable = 0;
    history[index] = value;
}

Number::Number(const Number& ref){
    index = 0;
    undoable = 0;
    history[index] = ref.Get();
}

Number::Number(Number&& ref){
    index = ref.index;
    undoable = ref.undoable;
    for(int i = 0; i < MAX_HISTORY; i++) history[i] = ref.history[i];
    ref.index = 0;
    ref.undoable = 0;
    ref.history = new double[MAX_HISTORY];
}

Number::~Number(){
    delete[] history;
}

double Number::Get() const{
    return history[index % MAX_HISTORY];
}

void Number::Set(double value){
    index++;
    if(undoable != MAX_HISTORY - 1) undoable++;
    history[index % MAX_HISTORY] = value;
}

void Number::Undo(){
    if(undoable > 0){
        history[index % MAX_HISTORY] = 0.0;
        index--;
        undoable--;
    }
}