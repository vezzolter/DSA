// Title:   Header file for Strassen's Algorithm
// Authors: by vezzolter
// Date:    April 13, 2024
// ----------------------------------------------------------------------------


#ifndef STRASSENS_H
#define STRASSENS_H


using Matrix = std::vector<std::vector<int>>;


Matrix addMatrices(const Matrix& A, const Matrix& B);
Matrix subtractMatrices(const Matrix& A, const Matrix& B);
Matrix strassensAlgorithm(const Matrix& A, const Matrix& B);


#endif // STRASSENS_H