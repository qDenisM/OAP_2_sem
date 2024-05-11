#include "10.h"
#include <fstream>

using namespace std;

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    clear();
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int Stack::pop() {
    if (isEmpty()) {
        cerr << "Ошибка: стек пустой.\n";
        return -1;
    }
    int data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::saveToFile(const char* filename) {
    ofstream outFile(filename);
    Node* current = top;
    while (current != nullptr) {
        outFile << current->data << "\n";
        current = current->next;
    }
    outFile.close();
}

void Stack::readFromFile(const char* filename) {
    clear();
    ifstream inFile(filename);
    int value;
    Node* lastNode = nullptr;
    while (inFile >> value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (lastNode == nullptr) {
            top = newNode;
        }
        else {
            lastNode->next = newNode;
        }
        lastNode = newNode;
    }
    inFile.close();
}

void Stack::printStack() {
    Node* current = top;
    cout << "Стек: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

bool Stack::isInRange(int low, int high) {
    Node* current = top;
    while (current != nullptr) {
        if (current->data >= low && current->data <= high) {
            return true;
        }
        current = current->next;
    }
    return false;
}
