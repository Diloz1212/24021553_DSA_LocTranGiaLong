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

    cout << sum << endl;

    delete[] arr;
    return 0;
}