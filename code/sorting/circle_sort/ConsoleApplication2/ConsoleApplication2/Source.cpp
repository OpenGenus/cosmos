#include"Employee.h"
int main() {
	int n;
	char k;
	string j;
	cout << "Enter number of Employees: ";
	cin >> n;
	Employee * arr = new Employee[n];
	while (true) {
		cout << "/------------------------------------------------/" << endl;
		cout << "If you want to enter the Employees data press D/d" << endl;
		cout << "If you want to display the Employees data press P/p" << endl;
		cout << "Department Inquiries M/m" << endl;
		cout << "If you want to end the program press E/e" << endl;
		cin >> k;

		if (k == 'D' || k == 'd') {
			for (int i = 0; i < n; i++) {
				cout << "Employee number" << i + 1 << " : " << endl;
				arr[i].read();
				arr[i].Rasie();
			}
		}
		else if (k == 'P' || k == 'p') {
			for (int i = 0; i < n; i++) {
				cout << "Employee " << i + 1 << " : ";
				arr[i].print();
			}
		}
		else if (k == 'M' || k == 'm') {
			cout << "Enter department name: ";
			cin >> j;
			for (int i = 0; i < n; i++) {
				arr[i].depprint(j);
			}

		}
		else if (k == 'E' || k == 'e') {
			break;
		}
		else cout << "Invalid entry" << endl;


	}

	return 0;
}
