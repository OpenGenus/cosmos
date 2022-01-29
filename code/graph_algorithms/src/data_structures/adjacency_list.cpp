#include <iostream>
#include <vector>
using namespace std;

//Used for printing out the adjList after you finish building it
void printList(vector<vector<int>> adjList)
{
	cout << "The adjacency list is: " << endl;
	for (int i = 0; i < adjList.size(); i++)
	{
		cout << "Vertex " << i + 1 << ": ";
		for (int j = 0; j < adjList[i].size(); j++)
		{
			cout << adjList[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int nodeNum;
	int numInput;
	char charInput;
	cout << "Input the number of nodes in the graph:" << endl;
	cin >> nodeNum;
	vector<vector<int>> adjList(nodeNum);
	for (int i = 0; i < nodeNum; i++)
	{
		bool moveOn = false;
		while (!moveOn)
		{
			cout << "Enter an edge for vertex " << i + 1 << ": " << endl;
			cin >> numInput;
			adjList[i].push_back(numInput);
			cout << "Do you want to add more edges? (y/n): " << endl;
			cin >> charInput;
			if (charInput == 'n')
				moveOn = true;
		}
	}
	printList(adjList);
	return 0;
}