#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int N;
    cout << "Enter array size N: ";
    cin >> N;
    vector<double> A(N), B(N);

    cout << "Array A: ";
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 21 - 10;
        cout << A[i] << " ";
    }
    cout << endl;

    double sumNeg = 0, sumPos = 0;
    int countNeg = 0, countPos = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) { sumNeg += A[i]; countNeg++; }
        else if (A[i] > 0) { sumPos += A[i]; countPos++; }
    }

    double avgNeg = (countNeg > 0) ? sumNeg / countNeg : 0;
    double avgPos = (countPos > 0) ? sumPos / countPos : 0;

    for (int i = 0; i < N; i++) {
        B[i] = A[i];
        if ((i + 1) % 2 == 0 && A[i] < 0) B[i] = avgNeg;
        if ((i + 1) % 2 != 0) B[i] = avgPos;
    }

    cout << "Array B: ";
    for (int i = 0; i < N; i++) cout << B[i] << " ";
    cout << endl;
    return 0;
}
