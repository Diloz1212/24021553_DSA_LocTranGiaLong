#include <iostream>
using namespace std;

// Độ phức tạp: O(N*M)
double sumOfMatrix(double** matrix, int rows, int cols) {
    double sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Độ phức tạp: O(N*M)
void deleteRow(double** matrix, int row, int& rows, int cols) {
    for (int i = row; i < rows - 1; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = matrix[i + 1][j];
        }
    }
    rows--;
}

int main() {
    int N, M;
    cin >> N >> M;
    double** matrix = new double*[N];

    for (int i = 0; i < N; i++) {
        matrix[i] = new double[M];
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    return 0;
}