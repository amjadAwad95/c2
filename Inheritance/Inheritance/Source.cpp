#include<iostream>
#include<time.h>
#include<random>

using namespace std;

class Person {
public:
	Person* parents[2];
	char alleles[2];
};

Person* createFamily(int generations);
char randomAllele();
void printInheritance(Person* child,int generations);
void deleteFamily(Person* child);

int main() {
	srand(time(NULL));
	int generations;
	do {
		cout << "Enter number of generations 1 or 2 or 3" << endl;
		cin >> generations;
	} while (generations != 1 && generations!=2 && generations != 3);
	Person* family = createFamily(generations);
	printInheritance(family,0);
	deleteFamily(family);
}

Person* createFamily(int generations) {
	Person* child = new Person;
	if (generations > 1) {
		if (generations == 2) {
			child->parents[0] = new Person;
			child->parents[1] = new Person;
			//------------------------------------------
			child->parents[0]->parents[0] = nullptr;
			child->parents[0]->parents[1] = nullptr;
			//-------------------------------------------
			child->parents[1]->parents[0] = nullptr;
			child->parents[1]->parents[1] = nullptr;
			//-------------------------------------------
			child->parents[0]->alleles[0] = randomAllele();
			child->parents[0]->alleles[1] = randomAllele();
			child->parents[1]->alleles[0] = randomAllele();
			child->parents[1]->alleles[1] = randomAllele();
			//-------------------------------------------
			int r = rand() % 2;;
			child->alleles[0] = child->parents[0]->alleles[r];
			r = rand() % 2;
			child->alleles[1] = child->parents[1]->alleles[r];
		}
		else if (generations == 3) {
			child->parents[0] = new Person;
			child->parents[1] = new Person;
			//--------------------------------------------------------
			Person* n = new Person;
			n->parents[0] = new Person;
			n->parents[1] = new Person;
			child->parents[0]->parents[0] = n->parents[0];
			child->parents[0]->parents[1] = n->parents[1];
			//--------------------------------------------------------
			n->parents[0] = new Person;
			n->parents[1] = new Person;
			child->parents[1]->parents[0] = n->parents[0];
			child->parents[1]->parents[1] = n->parents[1];
			//--------------------------------------------------------
			child->parents[0]->parents[0]->parents[0] = nullptr;
			child->parents[0]->parents[0]->parents[1] = nullptr;
			child->parents[0]->parents[0]->alleles[0] = randomAllele();
			child->parents[0]->parents[0]->alleles[1] = randomAllele();
			//---------------------------------------------------------
			child->parents[0]->parents[1]->parents[0] = nullptr;
			child->parents[0]->parents[1]->parents[1] = nullptr;
			child->parents[0]->parents[1]->alleles[0] = randomAllele();
			child->parents[0]->parents[1]->alleles[1] = randomAllele();
			//----------------------------------------------------------

			//--------------------------------------------------------
			child->parents[1]->parents[0]->parents[0] = nullptr;
			child->parents[1]->parents[0]->parents[1] = nullptr;
			child->parents[1]->parents[0]->alleles[0] = randomAllele();
			child->parents[1]->parents[0]->alleles[1] = randomAllele();
			//---------------------------------------------------------
			child->parents[1]->parents[1]->parents[0] = nullptr;
			child->parents[1]->parents[1]->parents[1] = nullptr;
			child->parents[1]->parents[1]->alleles[0] = randomAllele();
			child->parents[1]->parents[1]->alleles[1] = randomAllele();
			//----------------------------------------------------------

			int r = rand() % 2;;
			child->parents[0]->alleles[0] = child->parents[0]->parents[0]->alleles[r];
			r = rand() % 2;
			child->parents[0]->alleles[1] = child->parents[0]->parents[1]->alleles[r];
			//-----------------------------------------------------------
			r = rand() % 2;;
			child->parents[1]->alleles[0] = child->parents[0]->parents[0]->alleles[r];
			r = rand() % 2;
			child->parents[1]->alleles[1] = child->parents[0]->parents[1]->alleles[r];
			//-----------------------------------------------------------
			r = rand() % 2;;
			child->alleles[0] = child->parents[0]->alleles[r];
			r = rand() % 2;
			child->alleles[1] = child->parents[1]->alleles[r];
		}
	}
	else if (generations == 1) {
		child->parents[0] = nullptr;
		child->parents[1] = nullptr;
		child->alleles[0] = randomAllele();
		child->alleles[1] = randomAllele();
	}
	return child;
}
char randomAllele() {
	int r = rand() % 3;
	if (r == 0) {
		return 'A';
	}
	if (r == 1) {
		return 'B';
	}
	return 'O';
}
void printInheritance(Person * child,int generations) {
	if (child== nullptr) {
		return;
	}
	for (int i = 0; i <generations*(generations+1) ; i++) {
		cout << " ";
	}
	cout << "Generation " << generations << " " << "Blood type " << child->alleles[0] <<child->alleles[1] << " ";
	cout << endl;
	printInheritance(child->parents[0], generations + 1);
	printInheritance(child->parents[1], generations + 1);
}
void deleteFamily(Person* child) {
	if (child != nullptr) {
		if (child->parents[0] != nullptr) {
			delete child->parents[0]->parents[0];
			delete child->parents[0]->parents[1];
			delete child->parents[0];
		}
		if (child->parents[1] != nullptr) {
			delete child->parents[1]->parents[0];
			delete child->parents[1]->parents[1];
			delete child->parents[1];
		}
		delete child;
	}
}