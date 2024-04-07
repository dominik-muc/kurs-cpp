// Dominik Muc, 345952, Lista 5

#pragma once
#include <string>

class Queue{
protected:
    std::string* content;
    int capacity;
    int begin = 0;
    int count = 0;
public:
    void push(std::string value);
    std::string pop();
    std::string peek() const;
    int length() const;

    Queue(int capacity);
    Queue();
    Queue(std::initializer_list<std::string> args);
    Queue(const Queue& ref);
    Queue(Queue&& other);

    ~Queue();

    Queue& operator =(const Queue& ref);
    Queue& operator =(Queue&& other);
};