// Title:   Strassen's Algorithm
// Authors: by vezzolter
// Date:    April 13, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include <vector>
#include "StrassensAlgorithm.h"

using Matrix = std::vector<std::vector<int>>;


void printMatrix(const Matrix matrix) {
	int n = matrix.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << " " << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Matrix standardAlgorithm(const Matrix& A, const Matrix& B) {
	int n = A.size();
	Matrix C(n, std::vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Strassen's Algorithm' console application!\n\n";

	// Create initial matrices 
	Matrix A = {
		{1, 2, 3, 4}, 
		{5, 6, 7, 8}, 
		{9, 10, 11, 12}, 
		{13, 14, 15, 16}
	};
	
	Matrix B = {
		{17, 18, 19, 20}, 
		{21, 22, 23, 24}, 
		{25, 26, 27, 28}, 
		{29, 30, 31, 32}
	};
	//Matrix A = {{1, 2}, {3, 4}}; // 2x2
	//Matrix B = {{5, 6}, {7, 8} }; // 2x2
	std::cout << "Creating initial matrix A:" << std::endl;
	printMatrix(A);
	std::cout << "Creating initial matrix B:" << std::endl;
	printMatrix(B);

	// Multiply and display standard algorithm
	std::cout << "Standard matrix multiplication:" << std::endl;
	Matrix ansStandard = standardAlgorithm(A, B);
	printMatrix(ansStandard);

	// Multiply and display Strssen's algorrithm
	std::cout << "Strassen's matrix multiplication:" << std::endl;
	Matrix ansStrassens = strassensAlgorithm(A, B);
	printMatrix(ansStrassens);

	// Exit
	std::cout << "Thanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}