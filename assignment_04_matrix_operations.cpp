// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

// Printing matrix 
void printMatrix(int M[10][10], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << setw(5) << M[r][c];
        }
        cout << endl;
    }
    cout << endl;
}

// PART A — Transpose
void transposeMatrix(int A[10][10], int T[10][10], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            T[c][r] = A[r][c];
        }
    }
}

// PART B — Add Two Matrices
void addMatrices(int A[10][10], int B[10][10], int R[10][10],
                 int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            R[r][c] = A[r][c] + B[r][c];
        }
    }
}

// PART C — Multiply Two Matrices
void multiplyMatrices(int A[10][10], int B[10][10], int R[10][10],
                      int M, int N, int P) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            R[i][j] = 0;
            for (int k = 0; k < N; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Matrix from user
void readMatrix(int M[10][10], int &rows, int &cols) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << "Enter element [" << r << "][" << c << "]: ";
            cin >> M[r][c];
        }
    }
}

// The program
int main() {
    int A[10][10], B[10][10], R[10][10], T[10][10];
    int rowsA, colsA, rowsB, colsB;

    //PART A 
    cout << "\n=== PART A: TRANSPOSE A MATRIX ===\n";
    readMatrix(A, rowsA, colsA);

    cout << "\nOriginal Matrix:\n";
    printMatrix(A, rowsA, colsA);

    transposeMatrix(A, T, rowsA, colsA);
    cout << "Transposed Matrix:\n";
    printMatrix(T, colsA, rowsA);

    //PART B 
    cout << "\n=== PART B: ADD TWO MATRICES ===\n";
    cout << "Enter Matrix 1:\n";
    readMatrix(A, rowsA, colsA);

    cout << "Enter Matrix 2:\n";
    readMatrix(B, rowsB, colsB);

    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(A, B, R, rowsA, colsA);
        cout << "\nSum of Matrices:\n";
        printMatrix(R, rowsA, colsA);
    } else {
        cout << "\nError: Matrices must have the same dimensions.\n";
    }

    //PART C 
    cout << "\n=== PART C: MULTIPLY TWO MATRICES ===\n";
    cout << "Enter Matrix A:\n";
    readMatrix(A, rowsA, colsA);

    cout << "Enter Matrix B:\n";
    readMatrix(B, rowsB, colsB);

    if (colsA == rowsB) {
        multiplyMatrices(A, B, R, rowsA, colsA, colsB);
        cout << "\nProduct A × B:\n";
        printMatrix(R, rowsA, colsB);
    } else {
        cout << "\nError: Number of columns in A must equal number of rows in B.\n";
    }

    return 0;
}
