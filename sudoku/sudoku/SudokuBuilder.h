#pragma once
#include "Constant.h"
#include "SudokuJudger.h"

class SudokuBuilder {
public:
	void generateSudoku(int(&sudoku)[LENGTH][LENGTH]);

	int* randomArray(int row);

	int* randomArray(int column, int* temp);

	void initSudoku(int(&sudoku)[LENGTH][LENGTH]);

private:

};