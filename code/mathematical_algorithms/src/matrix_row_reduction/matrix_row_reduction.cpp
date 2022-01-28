#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

void PrintMatrix(vector<vector<float>>& matrix); //Prints matrix to console
int FirstNonZero(vector<float>& vec); //find first non-zero coefficient in a given row, returns -1 if unfound

void RowReduction(vector<vector<float>>& matrix) {
	//Reduces a matrix to it's reduced row echelon form
	int iteration = 0;
	while (iteration != matrix[0].size() - 1) {
		for (int i = iteration; i < matrix.size(); i++) {
			float divisor = 1;
			int pivot = FirstNonZero(matrix[i]);
			if (pivot != -1)
				divisor = matrix.at(i).at(pivot);
			for (int j = 0; j < matrix[i].size(); j++)
				if (pivot != -1)
					matrix[i][j] /= divisor;
		}
		for (int i = iteration + 1; i < matrix.size(); i++) {
			int pivot = FirstNonZero(matrix[iteration]);
			if (pivot != -1 && matrix[i][pivot] != 0) {
				for (int j = pivot; j < matrix.at(i).size(); j++) {
					matrix[i][j] -= matrix[iteration][j];
				}
			}
		}
		iteration++;
	}

	//correct the row order
	for (int i = 0; i < matrix.size(); i++) {
		int index = FirstNonZero(matrix.at(i));
		if (index == -1) {
			continue;
		}
		vector<float> temp = matrix[index];
		matrix[index] = matrix.at(i);
		matrix[i] = temp;
	}

	cout << "Row Echelon Form:" << endl;
	PrintMatrix(matrix);
	cout << endl;

	//test if system is consistent
	set<int> pivots;
	for (vector<float> row : matrix) {
		if (FirstNonZero(row) == -1) {
			if (row.back() != 0) {
				cout << "The System of Equations has No Solution" << endl;
				return;
			}
		}
		else
			pivots.insert(FirstNonZero(row));
	}
	unsigned int freeVar = matrix[0].size() - 1 - pivots.size();

	if (freeVar == 0)
		cout << "The System of Equations has one Solution" << endl;
	else
		cout << "The System of Equations has many Solutions" << endl;

	cout << "The System has " << freeVar << " free variable(s).\n" << endl;

	iteration = matrix.size() - 1;
	//Reduces the matrix to its reduced echelon form
	while (iteration > 0) {
		for (int i = 0; i < iteration; i++) {
			int pivot = FirstNonZero(matrix[iteration]);
			float multiple = 0;
			if (pivot != -1)
				multiple = matrix.at(i).at(pivot);
			for (int j = 0; j < matrix.at(i).size(); j++) {
				matrix[i][j] -= (matrix[iteration][j] * multiple);
			}
		}
		iteration--;
	}
	cout << "Reduced Echelon From:" << endl;
	PrintMatrix(matrix);



	if (freeVar == 0) { //Case 1 there is a single solution
		vector<float> solutions;
		solutions.resize(matrix[0].size() - 1);
		for (vector<float> row : matrix) {
			if (FirstNonZero(row) == -1)
				continue;
			float val = round(row.back() * 100.0) / 100.0;
			if (val == -0)
				val = 0;
			solutions.at(FirstNonZero(row)) = val;
		}

		cout << "\nThe solution to this set of Equations is (";
		for (float val : solutions) {
			if (val == solutions.back())
				cout << val << ")\n";
			else
				cout << val << ", ";
		}
	}
	else { //Case 2 there are infinite solutions
		vector<string> equations;
		equations.resize(matrix[0].size() - 1);
		for (vector<float> row : matrix) {
			int index = FirstNonZero(row);
			if (index == -1)
				continue;
			string equation = "";
			for (int i = index + 1; i < row.size(); i++) {
				float value = round(row[i] * 100.0) / 100.0;
				if (value != 0 && value != -0) {
					float absVal = abs(value);
					string temp = to_string(absVal);
					if (i == row.size() - 1) {
						if (equation == "") {
							if (value < 0)
								equation.append("-");
						}
						else {
							if (value > 0)
								equation.append(" + ");
							else
								equation.append(" - ");
						}
						equation.append(temp.substr(0, temp.find_first_of('.') + 3));
					}
					else {
						if (equation == "") {
							if (value > 0)
								equation.append("-");

						}
						else {
							if (value < 0)
								equation.append(" + ");
							else
								equation.append(" - ");
						}
						equation.append(temp.substr(0, temp.find_first_of('.') + 3) + "X" + to_string(i + 1));
					}
				}
			}
			equations[index] = equation;
		}
		cout << "\nThe solution set to this set of Equations is (";
		for (int i = 0; i < equations.size(); i++) {
			if (equations.at(i) == "")
				equations.at(i) = "X" + to_string(i + 1);
			if (i == equations.size() - 1)
				cout << equations.at(i) << ")\n";
			else
				cout << equations.at(i) << ", ";
		}
	}
}

//Prints Matrix
void PrintMatrix(vector<vector<float>>& matrix) {
	for (vector<float> row : matrix) {
		for (float value : row) {
			if (value == -0)
				cout << "0 ";
			else
				cout << value << " ";
		}
		cout << endl;
	}
}

//Find the index of the first non zero value in a row returns -1 if all but the last value are zero
int FirstNonZero(vector<float>& vec) {
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec.at(i) != 0 && vec.at(i) != -0)
			return i;
	}
	return -1;
}

void main() {
	//This is just the input for the matrix to solve the system of equations, just an example so you can use the algorithm
	cout << "Please insert the coefficients of each equation separated by semicolons (A;B;C:...:N;b)\nEquations should be in the form Ax + By + Cz + ... + Nn = b. Separate each equation with a new line." << endl << "Type 'solve' when finished" << endl;
	string input = "";
	string delimiter = ";";
	size_t pos = 0;
	vector<vector<float>> matrix;
	int row = 0;
	int columnSize = 0;
	while (1) {
		int currColumnSize = 0;
		vector<float> tempVec;
		getline(cin, input);
		if (input == "solve")
			break;
		while ((pos = input.find(delimiter)) != std::string::npos) {
			if (input.substr(0, pos).find_first_not_of("0123456789-") != std::string::npos) {
				cout << "Error: Invalid Coefficient\n\nCoefficient is not an integer" << endl;
				return;
			}
			int temp = stoi(input.substr(0, pos));
			tempVec.push_back(temp);;
			input.erase(0, pos + delimiter.length());
			currColumnSize++;
		}
		int temp = stoi(input);
		tempVec.push_back(temp);
		currColumnSize++;
		if (currColumnSize != columnSize && columnSize != 0) {
			cout << "Error: Invalid Formating" << endl << endl << "All Rows do not have the same number of columns.\nIf an equation is missing a variable there should be a coefficient of 0 to fill its place." << endl;
			return;
		}
		columnSize = currColumnSize;
		matrix.push_back(tempVec);
		row++;
	}
	cout << "\nMatrix you entered:" << endl;
	PrintMatrix(matrix);
	cout << endl;
	//This is where the actual algorithm starts
	RowReduction(matrix);
}


