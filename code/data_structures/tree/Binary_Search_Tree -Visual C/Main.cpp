#pragma once
#include <iostream>
#include "cBinTree.h"
#include <conio.h>
using namespace std;

int main()
{
	cBinTree g;


	while (true)
	{
		system("cls");
		char choice;
		cout << "select the #: " << endl;
		cout << "a.enter element: " << endl;
		cout << "b.Find the largest key: " << endl;
		//cout << "c.Find a unique key: " << endl;
		cout << "d.Find Degree of a key: " << endl;
		cout << "e.Find level of a node: "<<endl;
		cout << "f.Breadth First Search: " << endl;
		cout << "g.Exit: " << endl <<endl;
		cin >> choice;

		switch (choice)
		{
		case 'a':
			system ("cls");
			g.insert_node();
			break;
		case'b':
			system("cls");
			g.largest_key();
			break;
		case'f':
			system("cls");
			g.find_key();
			break;
		case'd':
			system("cls");
			g.find_degree();
			break;
		case'e':
			system("cls");
			g.find_level();
			
			break;
		case'g':
			exit(1);
		}
	}


	_getche();
	return 0;
}
