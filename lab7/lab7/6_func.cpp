#include <iostream>
#include "6.h"

using namespace std;

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    clear();
}

void Stack::push(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int Stack::pop() {
    if (isEmpty()) {
        cerr << "Стек пустой." << endl;
        return -1; 
    }
    int data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::saveToFile(const char* filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Невозможно открыть файл." << endl;
        return;
    }
    Node* current = top;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next;
    }
    file.close();
}

void Stack::readFromFile(const char* filename) {
    clear();
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Невозможно открыть файл." << endl;
        return;
    }
    int data;
    while (file >> data) {
        push(data);
    }
    file.close();
}

int Stack::countEqualNeighbors() {
    if (isEmpty()) {
        cerr << "Стек пустой." << endl;
        return -1;
    }
    int count = 0;
    Node* current = top;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            count++;
        }
        current = current->next;
    }
    return count;
}
