#include <iostream>
using namespace std;


// Độ phức tạp: O(N)
void simplifyFraction(int tu, int mau) {
    int gcd = 1;
    for(int i = 1; i < min(tu, mau); i++) {
        if(tu % i == 0 && mau % i == 0) {
            gcd = i;
        }
    }
    cout << tu/gcd << "/" << mau/gcd << endl;
}

int main() {
    int tu, mau;
    cin >> tu >> mau;

    simplifyFraction(tu, mau);

    return 0;
}