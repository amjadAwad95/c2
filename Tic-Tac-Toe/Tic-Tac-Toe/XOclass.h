#pragma once
#include<iostream>

using namespace std;

class XOclass {
private:
	int gameTable[3][3];
	bool isPlayerX;
	bool isPlayerO;
public:
	XOclass() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				gameTable[i][j] = 0;
			}
		}
		this->isPlayerX = true;
		this->isPlayerO = false;
	}
	XOclass(char start) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				gameTable[i][j] = 0;
			}
		}
		if (start == 'x' || start == 'X') {
			this->isPlayerX = true;
			this->isPlayerO = false;
		}
		else if (start == 'o' || start == 'O') {
			this->isPlayerX = false;
			this->isPlayerO = true;
		}
		else {
			this->isPlayerX = true;
			this->isPlayerO = false;
		}
	}
	void printGameTable() {
		cout << "| 1 | 2 | 3 |" << endl;
		cout << "-------------" << endl;
		cout << "| 4 | 5 | 6 |" << endl;
		cout << "-------------" << endl;
		cout << "| 7 | 8 | 9 |" << endl;
	}
	int isWinner() {
		if (gameTable[0][0] == gameTable[0][1] && gameTable[0][0] == gameTable[0][2] && gameTable[0][0]) {
			return gameTable[0][0];
		}
		else if (gameTable[1][0] == gameTable[1][1] && gameTable[1][0] == gameTable[1][2] && gameTable[1][0]) {
			return gameTable[1][0];
		}
		else if (gameTable[2][0] == gameTable[2][1] && gameTable[2][0] == gameTable[2][2] && gameTable[2][0]) {
			return gameTable[2][0];
		}
		else if (gameTable[0][0] == gameTable[1][0] && gameTable[0][0] == gameTable[2][0] && gameTable[0][0]) {
			return gameTable[0][0];
		}
		else if (gameTable[0][1] == gameTable[1][1] && gameTable[0][1] == gameTable[2][1] && gameTable[0][1]) {
			return gameTable[0][1];
		}
		else if (gameTable[0][2] == gameTable[1][2] && gameTable[0][2] == gameTable[2][2] && gameTable[0][2]) {
			return gameTable[0][2];
		}
		else if (gameTable[0][0] == gameTable[1][1] && gameTable[0][0] == gameTable[2][2] && gameTable[0][0]) {
			return gameTable[0][0];
		}
		else if (gameTable[0][2] == gameTable[1][1] && gameTable[0][2] == gameTable[2][0] && gameTable[0][2]) {
			return gameTable[0][2];
		}
		else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (gameTable[i][j] == 0) {
						return 0;
					}
				}
			}
		}
		return 3;
	}
	int player() {
		if (this->isPlayerX) {
			return 1;
		}
		return 2;
	}
	bool updateGameTable(int number) {
		if (number >= 1 && number <= 9) {
			switch (number) {
			case 1:
				if (gameTable[0][0] == 0)
					gameTable[0][0] = this->player();
				break;
			case 2:
				if (gameTable[0][1] == 0)
					gameTable[0][1] = this->player();
				break;
			case 3:
				if (gameTable[0][2] == 0)
					gameTable[0][2] = this->player();
				break;
			case 4:
				if (gameTable[1][0] == 0)
					gameTable[1][0] = this->player();
				break;
			case 5:
				if (gameTable[1][1] == 0)
					gameTable[1][1] = this->player();
				break;
			case 6:
				if (gameTable[1][2] == 0)
					gameTable[1][2] = this->player();
				break;
			case 7:
				if (gameTable[2][0] == 0)
					gameTable[2][0] = this->player();
				break;
			case 8:
				if (gameTable[2][1] == 0)
					gameTable[2][1] = this->player();
				break;
			case 9:
				if (gameTable[2][2] == 0)
					gameTable[2][2] = this->player();
				break;
			}
			return true;
		}
		return false;
	}
	void updateTable() {
		int number = 1;
		
		for (int i = 0; i < 3; i++) {
			cout << "| ";
			for (int j = 0; j < 3; j++) {
				if (gameTable[i][j] == 0) {
					cout << number <<" | ";
					number++;
				}
				else if (gameTable[i][j] == 1) {
					cout << "X | ";
					number++;
				}
				else {
					cout << "O | ";
					number++;
				}
			}
			cout << endl;
			cout << "-------------" << endl;
		}
	}
	void letsPlaye() {
		this->printGameTable();
		while (this->isWinner() == 0) {
			if (this->isPlayerX) {
				cout << "The player X enter number" << endl;
			}
			else {
				cout << "The player O enter number" << endl;
			}
			int number;
			do {
				cin >> number;
			} while (!this->updateGameTable(number));
			this->updateTable();

			if (this->isPlayerX) {
				this->isPlayerX = false;
				this->isPlayerO = true;
			}
			else {
				this->isPlayerO = false;
				this->isPlayerX = true;
			}
		}
		if (this->isWinner() == 1) {
			cout << "The player X is winner" << endl;
		}
		else if (this->isWinner() == 2) {
			cout << "The player O is winner" << endl;
		}
		else if (this->isWinner() == 3) {
			cout << "DRAW!" << endl;
		}
	}
};