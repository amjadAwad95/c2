#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct MyTime {
	int hour, min, sec;
	char f[10];
	void printTime() {
		cout << hour << " " << min << " " << sec << " " << f << endl;
	}
};

bool cheakTime(MyTime t);

int main() {
	ifstream myFile;
	myFile.open("Time.txt");
	if (!myFile.is_open()) {
		cout << "error" << endl;
		return 1;
	}
	int timeCounter = 0;
	string name;
	while (getline(myFile, name)) {
		timeCounter++;
	}
	myFile.close();
	myFile.open("Time.txt");
	if (!myFile.is_open()) {
		cout << "error" << endl;
		return 1;
	}
	MyTime* timeArray = new MyTime[timeCounter];
	for (int i = 0; i < timeCounter; i++) {
		myFile >> timeArray[i].hour >> timeArray[i].min >> timeArray[i].sec >> timeArray[i].f;
	}
	cout << "1) print time" << endl;
	cout << "2) cheak time" << endl;
	int chose;
	cin >> chose;
	switch (chose) {
	case 1:
		for (int i = 0; i < timeCounter; i++) {
			timeArray[i].printTime();
		}
	case 2:
		for (int i = 0; i < timeCounter; i++) {
			if (cheakTime(timeArray[i])) {
				cout<<"correct"<<endl;
			}
			else {
				cout<<"incorrect"<<endl;
			}
		}
	}
}

bool cheakTime(MyTime t) {
	if (strcmp(t.f, "am") == 0 || strcmp(t.f, "pm") == 0) {
		if (t.hour < 0 || t.hour>12) {
			return false;
		}
	}
	else {
		if (t.hour < 0 || t.hour>24) {
			return false;
		}
	}
	if (t.min < 0 || t.min>60) {
		return false;
	}
	if (t.sec < 0 || t.sec>60) {
		return false;
	}
	return true;
}