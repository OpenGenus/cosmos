/*
 * Part of Cosmos by OpenGenus Foundation
 */
#include <iostream>
#include <vector>
using namespace std;

//Used for printing out the adjList after you finish building it
void printMatrix(vector<vector<int>> adjMatrix)
{
	cout << "The adjacency matrix is: " << endl;
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		for (int j = 0; j < adjMatrix[i].size(); j++)
		{
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int nodeNum;
	int numInput;
	char charInput;
	cout << "Input the number of nodes in the graph" << endl;
	cin >> nodeNum;
	vector<vector<int>> adjMatrix(nodeNum, vector<int>(nodeNum)); //Initalizes a 2D vector of all 0s
	for (int i = 0; i < nodeNum; i++)
	{
		bool moveOn = false;
		while (!moveOn)
		{
			cout << "Enter an edge for vertex " << i + 1 << ": " << endl;
			cin >> numInput;
			if (numInput > nodeNum)
				cout << "Invalid input" << endl;
			else
				adjMatrix[i][numInput - 1] = 1;
			cout << "Do you want to add more edges? (y/n): " << endl;
			cin >> charInput;
			if (charInput == 'n')
				moveOn = true;
		}
	}
	//When printing the matrix, the rows is the source node and the columns are the destination
	printMatrix(adjMatrix);
	return 0;
}