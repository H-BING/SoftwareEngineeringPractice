#include"SudokuPlayer.h"
#include"SudokuBuilder.h"
#include"SudokuPrinter.h"

#include<time.h>
#include<stdlib.h>
#include<iostream>


void SudokuPlayer::playSudoku(int n) {

	srand((unsigned)time(NULL));
	freopen("sudoku.txt", "w", stdout);

	SudokuBuilder sudokuBuilder;
	SudokuPrinter sudokuPrinter;

	while (n--) {
		int sudoku[LENGTH][LENGTH];

		sudokuBuilder.generateSudoku(sudoku);
		sudokuPrinter.printSudoku(sudoku);
	}
}

int add::addNumber(int x, int y) {
	return x + y;
}