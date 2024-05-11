#pragma once
#define STACK_H

#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(int value);
    int pop();
    void clear();
    void saveToFile(const char* filename);
    void readFromFile(const char* filename);
    void printStack();
    bool isInRange(int low, int high);
};
