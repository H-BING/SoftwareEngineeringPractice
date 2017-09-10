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

void enjoySudoku(int n) {
	SudokuPlayer sudokuPlayer;
	sudokuPlayer.enjoySudoku(n);
}

/**
int main() {
	enjoySudoku(1000);
	//playSudoku(1);
	return 0;
}
**/

/**/
int main(int argc, char* argv[]) {

	SudokuPrinter sudokuPrinter;

	if (argc == 1) {
		sudokuPrinter.errorPrint(ERROR_INPUT_LACK_PARAM);
		return 0;
	} else if (argc > 3) {
		sudokuPrinter.errorPrint(ERROR_INPUT_EXTRA);
		return 0;
	}

	bool correctInputParam = false;

	for (int i = 1; i < argc; i++) {

		string input = argv[i];

		if (input == "-c") {
			correctInputParam = true;
		}

		if (correctInputParam) {
			if (argc == 2) {
				sudokuPrinter.errorPrint(ERROR_INPUT_LACK_NUMBER);
				break;
			} else {
				string figure = argv[++i];
				if (isInteger(figure)) {
					enjoySudoku(atoi(figure.c_str()));
					//playSudoku(atoi(figure.c_str()));
				} else {
					sudokuPrinter.errorPrint(ERROR_INPUT_ILLEGAL_NUMBER);
				}
			}
		} else {
			sudokuPrinter.errorPrint(ERROR_INPUT_ILLEAGL_PARAM);
			break;
		}
	}

	return 0;
}
/**/
