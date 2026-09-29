#include <iostream>
using namespace std;

// Độ phức tạp: O(N)
int main() {
    int N;
    cin >> N;
    double* arr = new double[N];
    double sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    double average = sum / N;

    for (int i = 0; i < N; i++) {
        if (arr[i] >= average) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    delete[] arr;
    return 0;
}