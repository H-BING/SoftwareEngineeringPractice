#include "SudokuGenerator.h"
#include <iostream>

void SudokuGenerator::DepthFirstSearch(int(&sudoku)[LENGTH][LENGTH], int count, int(&n)) {

	if (!n) {
		return;
	}

	if (count > 80) {
		sudokuPrinter.printSudoku(sudoku);
		--n;
		return;
	}

	int x = count / LENGTH, y = count % LENGTH;

	if (sudoku[x][y] != INITDATA) {
		DepthFirstSearch(sudoku, count + 1, n);
	}

	for (int j = 1; j <= LENGTH; j++) {

		if (sudokuJudger.checkRequirement(x, y, j, sudoku)) {
			sudoku[x][y] = j;
			DepthFirstSearch(sudoku, count + 1, n);
			if (!n) {
				return;
			}
			sudoku[x][y] = INITDATA;
		}
	}
}

void SudokuGenerator::initSudoku(int(&sudoku)[LENGTH][LENGTH]) {
	memset(sudoku, INITDATA, sizeof(sudoku));
}