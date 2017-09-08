#include "SudokuJudger.h"

bool SudokuJudger::judgeColumn(int x, int y, int value, int sudoku[LENGTH][LENGTH]) {
	for (int i = 0; i < x; i++) {
		if (sudoku[i][y] == value) {
			return false;
		}
	}
	return true;
}

bool SudokuJudger::judgeSmallSudoku(int x, int y, int value, int sudoku[LENGTH][LENGTH]) {
	int startX = x / 3 * 3;
	int startY = y / 3 * 3;
	for (int i = startX; i < x; i++) {
		for (int j = startY; j < startY + 3; j++) {
			if (sudoku[i][j] == INITDATA) break;
			else if (sudoku[i][j] == value) {
				return false;
			}
		}
	}
	return true;
}

bool SudokuJudger::meetRequirement(int x, int y, int value, int sudoku[LENGTH][LENGTH]) {
	return judgeColumn(x, y, value, sudoku) && judgeSmallSudoku(x, y, value, sudoku);
}

int SudokuJudger::judgeTempRow(int row, int* tempArray, int sudoku[LENGTH][LENGTH]) {
	int result = this->judgeTempRow(row, 0, tempArray, sudoku);
	return result;
}

int SudokuJudger::judgeTempRow(int row, int column, int* tempArray, int sudoku[LENGTH][LENGTH]) {
	for (int j = column; j < LENGTH; j++) {
		if (!meetRequirement(row, j, tempArray[j], sudoku)) {
			return j;
		}
	}
	return -1;
}