/*https://iq.opengenus.org/gaussian-naive-bayes/ python code and algorithm explanation here as reference, used some values from the sample data here too
using a file called files.csv for inputs
format is 3 columns, first 2 are for xA and xB, 3rd is for y
the third column has 0 to indicate false, 1 to indicate true
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

float Gaussian_Naive_Bayes() {
	ifstream file("inputs.csv");
	string input;
	vector<vector<int>> x;
	vector<int> y;
	getline(file, input); //get the first line that has labels out of the way
	
	//store inputs from file into correct vectors
	while (getline(file, input)) {
		string a;
		string b;
		string yInput;
		vector<int> temp;
		temp.resize(2);
		istringstream line(input);
		//get input for x
		getline(line, a, ',');
		temp[0] = stoi(a);
		getline(line, b, ',');
		temp[1] = stoi(b);
		x.push_back(temp);
		//get input for y
		getline(line, yInput, ',');
		y.push_back(stoi(yInput));
	}

	vector<vector<int>> x_train;
	vector<vector<int>> x_test;
	vector<int> y_train;
	vector<int> y_test;
	int ySize = y.size();
	//to help randomly select test variables
	srand(time(0));

	//test size is 0.3, inputs values into test variables
	while(y_test.size() < (int)ySize*0.25) {
		int randomNum = rand() % y.size();
		x_test.push_back(x[randomNum]);
		y_test.push_back(y[randomNum]);
		x.erase(x.begin() + randomNum);
		y.erase(y.begin() + randomNum);
	}
	
	float meany0xA = 0.0, meany1xA = 0.0, meany0xB = 0.0, meany1xB = 0.0;
	int y0Size = 0, y1Size = 0;
	
	//input values into train variables
	for (int i = 0; i < y.size(); i++) {
		x_train.push_back(x[i]);
		y_train.push_back(y[i]);
		
		if (y_train[i] == 0) {
			meany0xA += x_train[i][0];
			meany0xB += x_train[i][1];
			y0Size++;
		}
		else {
			meany1xA += x_train[i][0];
			meany1xB += x_train[i][1];
			y1Size++;
		}
	}
	
	meany0xA /= y0Size;
	meany0xB /= y0Size;
	meany1xA /= y1Size;
	meany1xB /= y1Size;
	double variancey0xA = 0.0, variancey0xB = 0.0, stdDevy0xA, stdDevy0xB;
	double variancey1xA = 0.0, variancey1xB = 0.0, stdDevy1xA, stdDevy1xB;
	
	//find the variance & mean for each y category (0 or 1)
	for (int i = 0; i < y_train.size(); i++) {
		if (y_train[i] == 0) {
			variancey0xA += pow(x_train[i][0] - meany0xA, 2);
			variancey0xB += pow(x_train[i][1] - meany0xB, 2);
		}
		else {
			variancey1xA += pow(x_train[i][0] - meany1xA, 2);
			variancey1xB += pow(x_train[i][1] - meany1xB, 2);
		}
	}

	stdDevy0xA = sqrt(variancey0xA);
	stdDevy0xB = sqrt(variancey0xB);
	stdDevy1xA = sqrt(variancey1xA);
	stdDevy1xB = sqrt(variancey1xB);

	//make y predictions based on tests with x
	double zScorey0xA, zScorey0xB, zScorey0, zScorey1xA, zScorey1xB, zScorey1;
	vector<int> y_pred;
	int numAccurate = 0;

	for (int i = 0; i < y_test.size(); i++) {
		zScorey0xA = (x_test[i][0] - meany0xA) / stdDevy0xA;
		zScorey0xB = (x_test[i][1] - meany0xB) / stdDevy0xB;
		zScorey0 = (zScorey0xA + zScorey0xB) / 2; //average the y0 zScores
		zScorey1xA = (x_test[i][0] - meany1xA) / stdDevy1xA;
		zScorey1xB = (x_test[i][1] - meany1xB) / stdDevy1xB;
		zScorey1 = (zScorey1xA + zScorey1xB) / 2; //average the y1 zScores
		
		if (abs(zScorey0) <= abs(zScorey1)) //smaller absolute value of zScore means higher probability
			y_pred.push_back(0);
		else
			y_pred.push_back(1);

		if (y_test[i] == y_pred[i])
			numAccurate++;
	}

	return ((float)numAccurate) / y_test.size();
}

int main() {
	cout <<"The accuracy of this algorithm is: " << Gaussian_Naive_Bayes();
	return 0;
}