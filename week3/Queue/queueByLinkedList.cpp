#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
    Queue() : front(nullptr), rear(nullptr) {}
};

bool isEmpty(Queue* q) {
    return q->front == nullptr;
}

// O(1)
void enqueue(Queue* q, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// O(1)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue is empty. Cannot dequeue.");
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == nullptr) {
        q->rear = nullptr;
    }
    delete temp;
    return value;
}

// O(1)
int peek(Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue is empty. Cannot peek.");
    }
    return q->front->data;
}

// O(n)
int size(Queue* q) {
    int count = 0;
    Node* current = q->front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}