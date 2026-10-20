#include <stdexcept>
using namespace std;

struct Stack {
    int* arr;
    int capacity;
    int topIndex;

    Stack(int size) : capacity(size), topIndex(-1) {
        arr = new int[capacity];
    }

    ~Stack() {
        delete[] arr;
    }
};

 bool isEmpty(Stack* s) {
    return s->topIndex == -1;
 }

 // O(1)
 void push(Stack* s, int value) {
    if (s->topIndex == s->capacity - 1) {
        throw runtime_error("Stack overflow. Cannot push.");
    }
    s->arr[++s->topIndex] = value;
 }

 // O(1)
 int pop(Stack* s) {
    if (isEmpty(s)) {
        throw runtime_error("Stack is empty. Cannot pop.");
    }
    return s->arr[s->topIndex--];
 }

 // O(1)
 int size(Stack* s) {
    return s->topIndex + 1;
 }

 // O(1)
 int top(Stack* s) {
    if (isEmpty(s)) {
        throw runtime_error("Stack is empty. Cannot retrieve top element.");
    }
    return s->arr[s->topIndex];
 }
