#pragma once
#include<iostream>
#include<string>
using namespace std;
class Employee
{
	string name;
	string Department;
	double salary;
	int date;


public:
	Employee(int, int);
	Employee();
	void read();
	double Rasie();
	void print();
	void depprint(string);


};

