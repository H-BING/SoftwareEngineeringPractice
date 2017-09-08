#include<cstdio>
#include<iostream>
#include<sstream>

#include"SudokuPlayer.h"
#include"SudokuPrinter.h"
#include"SudokuBuilder.h"

using namespace std;

void playSudoku(int n) {
	SudokuPlayer sudokuPalyer;
	sudokuPalyer.playSudoku(n);
}

bool isInteger(string str) {
	stringstream sin(str);
	int figure;
	char c;
	if (!(sin >> figure)) {
		return false;
	}
	if (sin >> c) {
		return false;
	}
	return true;
}

/**
int main() {
	playSudoku(1);
	return 0;
}
**/

/**/
int main(int argc, char* argv[]) {

	SudokuPrinter sudokuPrinter;

	if (argc > 3) {
		sudokuPrinter.errorPrint();
		return 0;
	}


	bool correctInput = false;

	for (int i = 1; i < argc; i++) {

		string input = argv[i];

		if (input == "-c") {
			correctInput = true;
		}

		if (correctInput) {
			string figure = argv[++i];
			if (isInteger(figure)) {
				playSudoku(atoi(figure.c_str()));
			} else {
				sudokuPrinter.errorPrint();
			}
		} else {
			sudokuPrinter.errorPrint();
			break;
		}
	}

	return 0;
}
/**/
