#pragma once
#include <iostream>
#include <fstream>

struct Node {
    int data;
    Node* next;
};

struct StackLinkedList {
public:
    StackLinkedList();
    ~StackLinkedList();

    void push(int value);
    int pop();
    bool isEmpty();
    void clear();
    void saveToFile(const char* filename);
    void readFromFile(const char* filename);

    StackLinkedList* splitEvenOdd();
    void display();
    void displayEven();
    void displayOdd();

private:
    Node* top;
};