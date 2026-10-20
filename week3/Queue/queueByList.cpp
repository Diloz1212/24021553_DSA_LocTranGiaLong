#include <stdexcept>
using namespace std;

struct Queue {
    int* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

    Queue(int size) : capacity(size), frontIndex(0), rearIndex(-1), count(0) {
        arr = new int[capacity];
    }

    ~Queue() {
        delete[] arr;
    }
};

bool isEmpty(Queue* q) {
    return q->count == 0;
}

// O(1)
void enqueue(Queue* q, int value) {
    if (q->count == q->capacity) {
        throw runtime_error("Queue overflow. Cannot enqueue.");
    }
    q->rearIndex = (q->rearIndex + 1) % q->capacity;
    q->arr[q->rearIndex] = value;
    q->count++;
}

// O(1)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue is empty. Cannot dequeue.");
    }
    int value = q->arr[q->frontIndex];
    q->frontIndex = (q->frontIndex + 1) % q->capacity;
    q->count--;
    return value;
}

// O(1)
int peek(Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue is empty. Cannot peek.");
    }
    return q->arr[q->frontIndex];
}

// O(1)
int size(Queue* q) {
    return q->count;
}