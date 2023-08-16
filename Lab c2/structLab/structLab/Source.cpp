#include<iostream>

using namespace std;

struct Points {
	double x;
	double y;
};

void makeAMatrix(double**& matrix, int row, int col);
void inputPoints(Points*& point, int size);
double computeDistanc(Points p1, Points p2);
void putDistancInMatrix(double**& matrix, Points* point, int size);
void printMatrix(double** matrix, int row, int col);

int main() {
	Points *point;
	int size;
	cout << "Enter points size" << endl;
	cin >> size;
	point = new Points[size];
	inputPoints(point, size);
	double** matrix;
	makeAMatrix(matrix,size,size);
	putDistancInMatrix(matrix, point, size);
	printMatrix(matrix, size, size);

}
void makeAMatrix(double**& matrix, int row, int col) {
	matrix = new double* [row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new double[col] {0};
	}
}
void inputPoints(Points*& point, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter the " << i + 1 << " point" << endl;
		cout << "X: " << endl;
		cin >> point[i].x;
		cout << "Y: " << endl;
		cin >> point[i].y;
	}
}
double computeDistanc(Points p1, Points p2) {
	return(sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}

void putDistancInMatrix(double** &matrix, Points *point, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = computeDistanc(point[i], point[j]);
		}
	}
}

void printMatrix(double** matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}