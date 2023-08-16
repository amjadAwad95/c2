#include<iostream>

using namespace std;

struct Student {
	char name[20];
	int avg;
};

int main() {
	Student* a[100];
	for (int i = 0; i < 4; i++) {
		a[i] = new Student;
	}
	for (int i = 0; i < 4; i++) {
		cout << "name:" << endl;
		cin >> a[i]->name;
		cout << "avg:" << endl;
		cin >> a[i]->avg;
	}
	int h = a[0]->avg;
	char n[20];
	strcpy_s(n, a[0]->name);
	for (int i = 1; i < 4; i++) {
		if (a[i]->avg > h) {
			h = a[i]->avg;
			strcpy_s(n,a[i]->name);
		}
	}
	cout << "The name is" << n << endl;
	for (int i = 0; i < 4; i++) {
		if (a[i]->name[0] == 'a') {
			cout << a[i]->name << endl;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			if (a[i]->avg > a[j]->avg) {
				Student temp;
				strcpy_s(temp.name, a[i]->name);
				temp.avg = a[i]->avg;
				strcpy_s(a[i]->name,a[j]->name);
				a[i]->avg = a[j]->avg;
				strcpy_s(a[j]->name, temp.name);
				a[j]->avg = temp.avg;

			}
		}
	}
	cout << "---------------------------------------------------------" << endl;
	for (int i = 0; i < 4; i++) {
		cout << a[i]->name << " " << a[i]->avg << endl;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			for (int k = 0; k < 20; k++) {
				if (a[i]->name[k] > a[j]->name[k]) {
					// Swap students[i] and students[j]
					Student temp;
					strcpy_s(temp.name, a[i]->name);
					temp.avg = a[i]->avg;
					strcpy_s(a[i]->name, a[j]->name);
					a[i]->avg = a[j]->avg;
					strcpy_s(a[j]->name, temp.name);
					a[j]->avg = temp.avg;
					break;
				}
			}
		}
	}
	cout << "---------------------------------------------------------" << endl;
	for (int i = 0; i < 4; i++) {
		cout << a[i]->name << " " << a[i]->avg << endl;
	}
}