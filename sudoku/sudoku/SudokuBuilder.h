#pragma once
#define LENGTH 9
#define INITDATA -1

class SudokuBuilder {
public:
	void generateSudoku(int(&sudoku)[LENGTH][LENGTH]);

	int* randomArray(int row);

	int* randomArray(int column, int* temp);

	void initSudoku(int(&sudoku)[LENGTH][LENGTH]);

private:

};