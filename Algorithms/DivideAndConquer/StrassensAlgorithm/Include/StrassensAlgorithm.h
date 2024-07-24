// Header file for Strassen's Algorithm
// by vezzolter
// April 13, 2024


#pragma once

using Matrix = std::vector<std::vector<int>>;


Matrix addMatrices(const Matrix& A, const Matrix& B);
Matrix subtractMatrices(const Matrix& A, const Matrix& B);
Matrix strassensAlgorithm(const Matrix& A, const Matrix& B);


