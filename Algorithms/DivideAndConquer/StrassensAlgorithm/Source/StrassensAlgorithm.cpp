// Title:   Source file for Strassen's Algorithm
// Authors: by vezzolter
// Date:    April 13, 2024
// ----------------------------------------------------------------------------


#include <vector>
#include "StrassensAlgorithm.h"

using Matrix = std::vector<std::vector<int>>;


Matrix addMatrices(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

Matrix subtractMatrices(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

Matrix strassensAlgorithm(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n == 1) {
        Matrix C(1, std::vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    } else {
        int half = n / 2;

        Matrix A11(half, std::vector<int>(half));
        Matrix A12(half, std::vector<int>(half));
        Matrix A21(half, std::vector<int>(half));
        Matrix A22(half, std::vector<int>(half));
        Matrix B11(half, std::vector<int>(half));
        Matrix B12(half, std::vector<int>(half));
        Matrix B21(half, std::vector<int>(half));
        Matrix B22(half, std::vector<int>(half));

        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + half];
                A21[i][j] = A[i + half][j];
                A22[i][j] = A[i + half][j + half];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + half];
                B21[i][j] = B[i + half][j];
                B22[i][j] = B[i + half][j + half];
            }
        }

        Matrix P1 = strassensAlgorithm(addMatrices(A11, A22), addMatrices(B11, B22));
        Matrix P2 = strassensAlgorithm(addMatrices(A21, A22), B11);
        Matrix P3 = strassensAlgorithm(A11, subtractMatrices(B12, B22));
        Matrix P4 = strassensAlgorithm(A22, subtractMatrices(B21, B11));
        Matrix P5 = strassensAlgorithm(addMatrices(A11, A12), B22);
        Matrix P6 = strassensAlgorithm(subtractMatrices(A21, A11), addMatrices(B11, B12));
        Matrix P7 = strassensAlgorithm(subtractMatrices(A12, A22), addMatrices(B21, B22));

        Matrix C11 = addMatrices(subtractMatrices(addMatrices(P1, P4), P5), P7);
        Matrix C12 = addMatrices(P3, P5);
        Matrix C21 = addMatrices(P2, P4);
        Matrix C22 = addMatrices(subtractMatrices(addMatrices(P1, P3), P2), P6);

        Matrix C(n, std::vector<int>(n));
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                C[i][j] = C11[i][j];
                C[i][j + half] = C12[i][j];
                C[i + half][j] = C21[i][j];
                C[i + half][j + half] = C22[i][j];
            }
        }

        return C;
    }
}