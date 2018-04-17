/*
This file contains the implementation of the product of two matrices 
and checking the equality of two matrices. The algorithms for them, respectively,
are in functions matrix_product() and matrix_eqaulity(). These implementations 
are based off of brute force iteration, 
and the multiplication implementation does not utilize tiling. 
*/

#include <iostream>
#include <vector>
using namespace std;

// void 
// matrix_product(int num_rows_A, int num_cols_A, 
// 				int num_rows_B, int num_cols_B, 
// 				vector<vector<int> > &A, 
// 				vector<vector<int> > &B,
// 				vector<vector<int> > &Result);

// bool 
// matrix_equality(int num_rows_A, int num_cols_A, 
// 				int num_rows_B, int num_cols_B, 
// 				vector<vector<int> > &A, 
// 				vector<vector<int> > &B);

void 
matrix_product(int num_rows_A, int num_cols_A, 
				int num_rows_B, int num_cols_B, 
				vector<vector<int> > &A, 
				vector<vector<int> > &B,
				vector<vector<int> > &Result)  
{
	/* 
	From 'https://en.wikipedia.org/wiki/Matrix_multiplication':
	If A is an n x m matrix and B is an m x p matrix, 
	their matrix product AB is an n x p matrix 
	*/
	if (num_cols_A != num_rows_B) {
		cout << "Matrix multiplication not possible!\n";
		return; 
	}

	else {
		/* make Result's dimensions num_rowsA x num_colsB */
		Result.resize(num_rows_A);
		for (int i = 0; i < num_rows_A; i++) {
			Result[i].resize(num_cols_B);
		}

		/* Multiplication part: A row and column of product is obtained from the
		row of A being multiplied with the column of B
		*/
		for (int i = 0; i < num_rows_A; i++) {
			for (int j = 0; j < num_cols_B; j++) {
				for (int k = 0; k < num_rows_B; k++) {
					Result[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	}

	for (int i = 0; i < num_rows_A; i++) {
		for (int j = 0 ; j < num_cols_B; j++) {
			cout << Result[i][j] << " ";
		}
		cout << endl;
	}

}

bool 
matrix_equality(int num_rows_A, int num_cols_A, 
				int num_rows_B, int num_cols_B, 
				vector<vector<int> > &A, 
				vector<vector<int> > &B)   
{
	//for two matrices to be equal, they first need to have the same dimensions
	if ((num_rows_A == num_rows_B) && (num_cols_A == num_cols_B)) {
		for (int i = 0; i < num_rows_A; i++) {
			for (int j = 0; j < num_cols_A; j++) {
				if (A[i][j] != B[i][j]) {
					return false;
				}
			}
		} 
		/*if no element between A and B were mismtached, they are all the same */
		return true;

	} else {
		return false;
	}

}



int 
main() 
{

	vector<vector<int> > matA;
	vector<vector<int> > matB;
	int num_rowsA, num_rowsB, num_colsA, num_colsB;

	cout << "Num rows for matrix A:";
	cin >> num_rowsA;
	cout << "Num cols for matrix A:";
	cin >> num_colsA;

	/* make matA's dimensions num_rowsA x num_colsA */
	matA.resize(num_rowsA);
	for (int i = 0; i < num_rowsA; i++) {
		matA[i].resize(num_colsA);
	}

	cout << "Num rows for matrix B:";
	cin >> num_rowsB;
	cout << "Num columns for matrix B:";
	cin >> num_colsB;

	/* make matB's dimensions num_rowsB x num_colsB */
	matB.resize(num_rowsB);
	for (int i = 0; i < num_rowsB; i++) {
		matB[i].resize(num_colsB);
	}

	cout << "Put in elements for matrix A one by one\n";
	for (int i = 0; i < num_rowsA; i++) {
		for (int j = 0; j < num_colsA; j++) {
			cin >> matA[i][j];
		}
	}

	cout << "Put in elements for matrix B one by one\n";
	for (int i = 0; i < num_rowsB; i++) {
		for (int j = 0; j < num_colsB; j++) {
			cin >> matB[i][j];
		}
	}

	char mode;
	cout << "Put in p for product, e for equality, b for both\n";
	cin >> mode;

	if (mode == 'p') {
		//Product for matrix A and B
		vector<vector<int> > Result;
		matrix_product(num_rowsA, num_colsA, num_rowsB, num_colsB, matA, matB, Result);	
	}
	else if (mode == 'e') {
		//Equality for matrix A and B
		bool are_matrices_equal;
		are_matrices_equal =  matrix_equality(num_rowsA, num_colsA, num_rowsB, num_colsB, matA, matB);
		cout << "Are Matrices A and B equal? " << are_matrices_equal << "\n";

	}
	else if (mode == 'b') {
		vector<vector<int> > Result;
		matrix_product(num_rowsA, num_colsA, num_rowsB, num_colsB, matA, matB, Result);	

		bool are_matrices_equal;
		are_matrices_equal =  matrix_equality(num_rowsA, num_colsA, num_rowsB, num_colsB, matA, matB);
		cout << "Are Matrices A and B equal? " << are_matrices_equal << "\n";
	}
	else {
		cout << "Invalid input\n";
	}

	return 0;
}