#pragma once
#define LENGTH 9
#define INITDATA -1
class SudokuJudger {

public:

	//bool judgeTempRow(int i, int* temp, int sudoku[LENGTH][LENGTH]);

	/********** new **********/
	int judgeTempRow(int row, int* tempArray, int sudoku[LENGTH][LENGTH]);

	int judgeTempRow(int row, int column, int* tempArray, int sudoku[LENGTH][LENGTH]);

	/********** end **********/

private:
	bool judgeColumn(int x, int y, int value, int sudoku[LENGTH][LENGTH]);

	bool judgeSmallSudoku(int x, int y, int value, int sudoku[LENGTH][LENGTH]);

	bool meetRequirement(int x, int y, int value, int sudoku[LENGTH][LENGTH]);

};