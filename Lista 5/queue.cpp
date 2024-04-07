// Dominik Muc, 345952, Lista 5

#include "queue.hpp"
#include <stdexcept>

void Queue::push(std::string value){
    if(count == capacity) throw std::out_of_range("Queue is full.");
    content[(begin + count) % capacity] = value;
    count++;
}

std::string Queue::pop(){
    if(count == 0) throw std::invalid_argument("Queue is empty");
    std::string ret = content[begin % capacity];
    begin++;
    count--;
    return ret;
}

std::string Queue::peek() const {
    if(count == 0) throw std::invalid_argument("Queue is empty");
    return content[begin % capacity];
}

int Queue::length() const {
    return count;
}

Queue::Queue(int capacity){
    this->capacity = capacity;
    this->content = new std::string[capacity];
}

Queue::Queue() : Queue(1) {};

Queue::Queue(std::initializer_list<std::string> args) : Queue(args.size()){
    for(std::string it : args){
        push(it);
    }
}

Queue::Queue(const Queue& ref) : Queue(ref.length()){
    for(int i = 0; i < ref.length(); i++){
        push(ref.content[(ref.begin + i) % ref.count]);
    }
}

Queue::Queue(Queue&& other) : Queue(other.length()){
    delete[] content;
    
    content = other.content;
    capacity = other.capacity;
    begin = other.begin;
    count = other.count;

    other.content = nullptr;
    other.capacity = 0;
    other.begin = 0;
    other.count = 0;
}

Queue::~Queue(){
    delete[] content;
}

Queue& Queue::operator =(const Queue& ref){
    if(this == &ref) return *this;

    delete[] content;
    capacity = ref.capacity;
    content = new std::string[capacity];

    count = ref.count;
    begin = 0;

    for(int i = 0; i < ref.count; ++i){
        content[i] = ref.content[(ref.begin + i) % ref.capacity];
    }
    return *this;
}

Queue& Queue::operator =(Queue&& other){
    if(this == &other) return *this;

    delete[] content;
    
    content = other.content;
    capacity = other.capacity;
    begin = other.begin;
    count = other.count;

    other.content = nullptr;
    other.capacity = 0;
    other.begin = 0;
    other.count = 0;
    return *this;
}
