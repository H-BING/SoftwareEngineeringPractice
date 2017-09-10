#pragma once
#include "Constant.h"
#include "SudokuJudger.h"
#include "SudokuPrinter.h"

class SudokuGenerator {
public:

	void DepthFirstSearch(int(&sudoku)[LENGTH][LENGTH], int count, int(&n));

	void initSudoku(int(&sudoku)[LENGTH][LENGTH]);

private:

	SudokuJudger sudokuJudger;

	SudokuPrinter sudokuPrinter;

};