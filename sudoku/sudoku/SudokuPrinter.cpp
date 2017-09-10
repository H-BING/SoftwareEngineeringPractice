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
			char num = '0' + sudoku[i][j];
			if(j!= 0)putchar(' ');
			putchar(num);

			/**
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
		puts("");
		//printf("\n");

		/**
		if (i != 8 && i % 3 == 2) {
			printf("*******************\n");
		}
		**/
	}
	puts("");
	//printf("\n");
}
/**/

void SudokuPrinter::errorPrint(int error) {
	/**
	string path = PATH;

	ofstream output;
	output.open(path.c_str(), ios::out);
	output << "Illegal input!" << endl;
	output.close();
	**/

	//printf("Illegal input!\n");

	switch (error) {
	case ERROR_INPUT_EXTRA:
		printf("Your input contains something extra!\n");
		break;
	case ERROR_INPUT_ILLEAGL_PARAM:
		printf("Please input \"-c\" as the parameter used to generate sudoku!\n");
		break;
	case ERROR_INPUT_ILLEGAL_NUMBER:
		printf("Please input a positive integer as the number of sudoku!\n");
		break;
	case ERROR_INPUT_LACK_PARAM:
		printf("Maybe you want to generate N sudoku.\n");
		printf("Please input \"sudoku.exe -c N\" where N is a positive integer!\n");
		break;
	case ERROR_INPUT_LACK_NUMBER:
		printf("Please input the number of sudoku after \"-c\"!\n");
		break;
	default:
		break;
	}

}

