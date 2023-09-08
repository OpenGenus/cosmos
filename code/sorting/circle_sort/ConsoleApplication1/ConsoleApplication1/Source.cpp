#include <iostream>
#include <string>
using namespace std;

class employee
{
	string name;
	string depart;
	int date;
	double salary;

public:
	employee();
	employee(int d, int s);
	void read();
	void calc();
	void display(string pos);
};

employee::employee()
{
	name = " ";
	depart = " ";
	date = 0;
	salary = 0;
}
employee::employee(int d, int s)
{
	name = " ";
	depart = " ";
	date = d;
	salary = s;
}
void employee::read()
{
	cout << "Enter Names of Employees \n";
	cin >> name;
	cout << "Enter Salary of Employees \n";
	cin >> salary;
	cout << "Enter Date of Employees \n";
	cin >> date;
	cout << "Enter Depart of Employees \n";
	cin >> depart;
}
void employee::calc()
{
	if ((2017 - date) >= 5)
		salary += (salary*0.2);
}
void employee::display(string pos)
{
	cout << "Total salary is : " << salary << endl;

	if (pos == depart){
		cout << name << endl;
	}
}

int main()
{
	int size;
	cout << "enter how many employees \n ";
	cin >> size;
	employee *emp = new employee[size];
	for (int i = 0; i<size; i++){
		emp[i].read();
		emp[i].calc();
	}
	string s;
	cout << "enter department \n ";
	cin >> s;
	for (int i = 0; i<size; i++){
		emp[i].display(s);
	}
	delete[]emp;
	return 0;
}