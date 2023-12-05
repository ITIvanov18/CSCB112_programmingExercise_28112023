// Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;

/* Task 2: Demonstrate the transmission of two-dimensional arrays as
parameters of functions, the task of multiplication of is realized
matrices via functions:*/

void NewDinamicArray2(double**, unsigned, unsigned);
void EnterAMatrix(double**, unsigned, unsigned);
void MatrixMultiplication(double**, double**, double**, unsigned,
    unsigned, unsigned);
void OutputMatrix2(double**, unsigned, unsigned);
void FreeMemoryArray2(double**, unsigned);

void NewDinamicArray2(double** X, unsigned M, unsigned N) {
    for (int i = 0; i <= M - 1; i++)
        X[i] = new double[N];
}
void EnterAMatrix(double** X, unsigned M, unsigned N) {
    for (int i = 0; i <= M - 1; i++)
        for (int j = 0; j <= N - 1; j++) {
            cout << "[" << i << "][" << j << "]=";
            cin >> X[i][j];
        }
}

void MatrixMultiplication(double** A, double** B,
    double** C, unsigned M,
    unsigned N, unsigned K) {
    //C = A x B
    double elC = 0.0;
    for (int i = 0; i <= M - 1; i++) {
        for (int h = 0; h <= K - 1; h++) {
            elC = 0.0;
            for (int j = 0; j <= N - 1; j++) {
                elC += A[i][j] * B[j][h];
            }
            C[i][h] = elC;
        }
    }
}

void OutputMatrix2(double** X, unsigned M, unsigned N) {
    for (int i = 0; i <= M - 1; i++) {
        for (int h = 0; h <= N - 1; h++) {
            cout << setw(4) << X[i][h];
        }
        cout << endl;
    }
}

void FreeMemoryArray2(double** X, unsigned N) {
    for (int i = 0; i <= N - 1; i++)
        delete[] X[i];
    delete[] X;
    X = NULL;
}


int main() {
    double** A = NULL, ** B = NULL, ** C = NULL;
    unsigned M = 0, N = 0, F = 0, K = 0;

    cout << "Matrix A:\n";
    cout << "Enter the number of rows: ";
    cin >> M;
    cout << "Enter the number of columns: ";
    cin >> N;
    cout << "Matrix B:\n";
    cout << "Enter the number of rows: ";
    cin >> F;
    cout << "Enter the number of columns: ";
    cin >> K;

    if (N != F) {
        cout << "Number of the columns of A does not equal "
            << "to the number of the rows of B!!!\n";
        return 0;
    }
    cout << "Therefore, C( " << M << ", " << K << " ) = AB = ?\n";

    A = new double* [M];
    B = new double* [F];
    C = new double* [M];

    NewDinamicArray2(A, M, N);
    NewDinamicArray2(B, F, K);
    NewDinamicArray2(C, M, K);

        cout << "Enter matrix A:\n";
    EnterAMatrix(A, M, N);

    cout << "Enter matrix B:\n";
    EnterAMatrix(B, F, K);

    cout << "C = A x B :\n";
    MatrixMultiplication(A, B, C, M, N, K);
    OutputMatrix2(C, M, K);
    FreeMemoryArray2(A, M);
    FreeMemoryArray2(B, N);
    FreeMemoryArray2(C, M);

    return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
