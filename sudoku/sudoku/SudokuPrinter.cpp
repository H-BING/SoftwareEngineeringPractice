#include"SudokuPrinter.h"

#include<cstdio>
#include<fstream>

using namespace std;

/**
void SudokuPrinter::printSudoku(int sudoku[LENGTH][LENGTH]) {

	string path = "sudoku.txt";

	ofstream output;
	output.open(path.c_str(), ios::out);

	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (j == 0) {
				output << sudoku[i][j];
			} else {
				output << " " << sudoku[i][j];
			}
		}
		output << endl;
	}
	output << endl;

	output.close();
}
**/
/**/
void SudokuPrinter::printSudoku(int sudoku[LENGTH][LENGTH]) {

	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (j == 0) {
				printf("%d", sudoku[i][j]);
			} else {
				printf(" %d", sudoku[i][j]);
			}
			/**
			if (j != 0 && j % 3 == 0) {
				printf("|");
			} else {
				printf(" ");
			}
			printf("%d", sudoku[i][j]);
			**/
		}
		printf("\n");

		/**
		if (i != 8 && i % 3 == 2) {
			printf("*******************\n");
		}
		**/
	}
	printf("\n");
}
/**/

void SudokuPrinter::errorPrint() {
	string path = PATH;

	ofstream output;
	output.open(path.c_str(), ios::out);
	output << "Illegal input!" << endl;
	output.close();

	//printf("Illegal input!\n");
}

