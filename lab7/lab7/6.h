#define STACK_H
#include <fstream>

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
    void push(int data);
    int pop();
    bool isEmpty();
    void clear();
    void saveToFile(const char* filename);
    void readFromFile(const char* filename);
    int countEqualNeighbors();
};