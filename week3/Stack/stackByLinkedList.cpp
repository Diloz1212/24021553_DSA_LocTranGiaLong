#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
    Stack() : top(nullptr) {}
};

bool isEmpty(Stack* s) {
    return s->top == nullptr;
}

// O(1)
void push(Stack* s, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// O(1)
int pop(Stack* s) {
    if(isEmpty(s)) {
        throw runtime_error("Stack is empty. Cannot pop.");
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    delete temp;
    return value;
}

// O(n)
int size(Stack* s) {
    int count = 0;
    Node* current = s->top;
    while(current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// O(1)
int top(Stack* s) {
    if(isEmpty(s)) {
        throw runtime_error("Stack is empty. Cannot retrieve top element.");
    }
    return s->top->data;
}

int main() {
}