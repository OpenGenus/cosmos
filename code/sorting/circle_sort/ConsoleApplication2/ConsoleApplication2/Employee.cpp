#include "Employee.h"



Employee::Employee()
{
	salary = date = 0;


}
Employee::Employee(int sal, int date) {
	date = 0;
	sal = 0;
}

void Employee::read() {
	cout << "Enter Employee name: ";
	cin >> name;
	cout << "Enter this Employee department: ";
	cin >> Department;
	cout << "Enter this Employee base salary: ";
	cin >> salary;
	cout << "Enter number of working years: ";
	cin >> date;
	cout << "/------------------------------------------------------------/" << endl;;
}
double Employee::Rasie() {
	if (date >= 5) {
		return salary += (salary*0.2);
	}
	else return 0;
}
void Employee::print() {
	cout << "Name: " << name << endl;
	cout << "Department: " << Department << endl;
	cout << "Salary: " << salary << endl;
	cout << "/---------------------------------------------------------/" << endl;

}
void Employee::depprint(string k) {
	if (k == Department) {
		cout << "Name: " << name << endl;
	}
}

