#include<stdlib.h>
#include<time.h>
#include<iostream>
#include "SudokuBuilder.h"
#include "SudokuJudger.h"
using namespace std;

int* SudokuBuilder::randomArray(int row) {
	int* temp = new int[LENGTH] {3, 2, 1, 4, 5, 6, 7, 8, 9};

	int start = 0;
	if (row == 0) {
		start = 1;
	}
	for (int i = start; i < LENGTH; i++) {
		int random = (rand() % (LENGTH - i)) + i;
		swap(temp[i], temp[random]);
	}
	return temp;
}

int* SudokuBuilder::randomArray(int column, int* tempArray) {
	int random = (rand() % (LENGTH - column)) + column;
	swap(tempArray[column], tempArray[random]);
	return tempArray;
}

void SudokuBuilder::initSudoku(int(&sudoku)[LENGTH][LENGTH]) {
	memset(sudoku, INITDATA, sizeof(sudoku));
}

void SudokuBuilder::generateSudoku(int(&sudoku)[LENGTH][LENGTH]) {

	initSudoku(sudoku);

	SudokuJudger sudokuJuder;

	memcpy(sudoku[0], randomArray(0), sizeof(int) * LENGTH);
	for (int i = 1; i < LENGTH; i++) {
		int* tempArray = randomArray(i);
		bool succeed = false;
		while (!succeed) {
			int column = sudokuJuder.judgeTempRow(i, tempArray, sudoku);

			if (column == -1) {
				succeed = true;
			} else {
				tempArray = randomArray(column, tempArray);
				int tempColumn = sudokuJuder.judgeTempRow(i, tempArray, sudoku);
				if (tempColumn == column) {
					tempArray = randomArray(i);
				}
			}
		}
		memcpy(sudoku[i], tempArray, sizeof(int) * LENGTH);
	}
}
