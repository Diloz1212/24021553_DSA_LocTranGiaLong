#include <iostream>
using namespace std;

// Độ phức tạp: O(N^2)
void bubbleSort(double* arr, int N) {
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < N-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    double* arr = new double[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, N);

    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}