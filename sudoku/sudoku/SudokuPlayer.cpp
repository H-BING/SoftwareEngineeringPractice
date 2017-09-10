#include"SudokuPlayer.h"
#include"SudokuBuilder.h"
#include"SudokuPrinter.h"
#include"SudokuGenerator.h"

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

void SudokuPlayer::enjoySudoku(int n) {

	freopen(PATH, "w", stdout);

	int sudoku[LENGTH][LENGTH];
	SudokuGenerator sudokuGenerator;
	sudokuGenerator.initSudoku(sudoku);

	sudoku[0][0] = 3;

	sudokuGenerator.DepthFirstSearch(sudoku, 0, n);

}

int add::addNumber(int x, int y) {
	return x + y;
}