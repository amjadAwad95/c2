#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//file ->stdin,stdeout
//cmd =stdin
//istream cin
//ostream cout

int main() {
	/*
	ifstream amjad;
	amjad.open("number.txt");
	if (!amjad.is_open()) {
		cout << "An error" << endl;
		return 1;
	}
	int x;
	while (amjad >> x) {
		cout << x << endl;
	}
	*/
	/*
	ifstream p;
	p.open("Text.txt");
	if (!p.is_open()) {
		cout << "Error" << endl;
		return 1;
	}
	string pp;
	while (p >> pp) {
		cout << pp << endl;
	}
	*/
	/*
	ifstream myFile;
	myFile.open("Text.txt");
	if (!myFile.is_open()) {
		cout << "Error" << endl;
		return 1;
	}
	string name;
	int avg;
	while (myFile >> name >> avg) {
		cout << name << "\t" << avg << endl;
	}
	myFile.close();
	*/
	
		// Creation of ofstream class object
		ofstream fout;

		string line;

		// by default ios::out mode, automatically deletes
		// the content of file. To append the content, open in ios:app
		// fout.open("sample.txt", ios::app)
		fout.open("sample.txt");

		// Execute a loop If file successfully opened
		while (fout) {

			// Read a Line from standard input
			getline(cin, line);

			// Press -1 to exit
			if (line == "-1")
				break;

			// Write line in file
			fout << line << endl;
		}

		// Close the File
		fout.close();

		// Creation of ifstream class object to read the file
		ifstream fin;

		// by default open mode = ios::in mode
		fin.open("sample.txt");

		// Execute a loop until EOF (End of File)
		while (getline(fin, line)) {

			// Print line (read from file) in Console
			cout << line << endl;
		}

		// Close the file
		fin.close();
}