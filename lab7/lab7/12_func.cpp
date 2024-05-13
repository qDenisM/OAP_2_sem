#include "12.h"

using namespace std;

StackLinkedList::StackLinkedList() {
    top = nullptr;
}

StackLinkedList::~StackLinkedList() {
    clear();
}

void StackLinkedList::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int StackLinkedList::pop() {
    if (isEmpty()) {
        cerr << "Стек пустой." << endl;
        return -1;
    }
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

bool StackLinkedList::isEmpty() {
    return top == nullptr;
}

void StackLinkedList::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void StackLinkedList::saveToFile(const char* filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Невозможно открыть файл" << endl;
        return;
    }
    Node* current = top;
    while (current != nullptr) {
        file << current->data << " ";
        current = current->next;
    }
    file.close();
}

void StackLinkedList::readFromFile(const char* filename) {
    clear();
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Невозможно открыть файл." << endl;
        return;
    }
    int value;
    while (file >> value) {
        push(value);
    }
    file.close();
}

StackLinkedList* StackLinkedList::splitEvenOdd() {
    StackLinkedList* stackEven = new StackLinkedList();
    StackLinkedList* stackOdd = new StackLinkedList();
    Node* current = top;
    while (current != nullptr) {
        if (current->data % 2 == 0) {
            stackEven->push(current->data);
        }
        else {
            stackOdd->push(current->data);
        }
        current = current->next;
    }
    return stackEven;
}

void StackLinkedList::display() {
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void StackLinkedList::displayEven() {
    Node* current = top;
    while (current != nullptr) {
        if (current->data % 2 == 0) {
            cout << current->data << " ";
        }
        current = current->next;
    }
    cout << endl;
}

void StackLinkedList::displayOdd() {
    Node* current = top;
    while (current != nullptr) {
        if (current->data % 2 != 0) {
            cout << current->data << " ";
        }
        current = current->next;
    }
    cout << endl;
}
