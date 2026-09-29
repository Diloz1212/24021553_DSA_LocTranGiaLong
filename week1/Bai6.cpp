#include <iostream>
using namespace std;

// Độ phức tạp: O(N)
void deleteElement(double* arr, int index, int& N) {
    for (int i = index; i < N - 1; i++) {
        arr[i] = arr[i + 1];
    }
    N--;
}

// Độ phức tạp: O(N)
void addElement(double* arr, int index, int& N, double value) {
    for (int i = N; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    N++;
}
