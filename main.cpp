#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int N = 14;
    double A[N] = {5, -2, 3, -4, 7, 8, -1, 6, -9, 2, 4, -3, 10, -6};
    double B[N];
    double sumNeg = 0, sumPos = 0;
    int countNeg = 0, countPos = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] < 0) { sumNeg += A[i]; countNeg++; }
        else if (A[i] > 0) { sumPos += A[i]; countPos++; }
    }

    double avgNeg = sumNeg / countNeg;
    double avgPos = sumPos / countPos;

    for (int i = 0; i < N; i++) {
        B[i] = A[i];
        if ((i + 1) % 2 == 0 && A[i] < 0) B[i] = avgNeg;
        if ((i + 1) % 2 != 0) B[i] = avgPos;
    }

    cout << fixed << setprecision(2);
    cout << "Array A: ";
    for (int i = 0; i < N; i++) cout << setw(7) << A[i];
    cout << "\nArray B: ";
    for (int i = 0; i < N; i++) cout << setw(7) << B[i];
    cout << endl;
    return 0;
}
