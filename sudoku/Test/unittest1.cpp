#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sudoku/SudokuPlayer.h"
#include "../sudoku/SudokuBuilder.h"
#include "../sudoku/SudokuPrinter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			add add;
			int x = 1, y = 2, result = 3;
			int real = add.addNumber(x, y);
			Assert::AreEqual(real, result);
		}

		TEST_METHOD(playSudoku) {
			// TODO: �ڴ�������Դ���
			SudokuPlayer sudokuPlayer;
			sudokuPlayer.playSudoku(1);
		}


	};
}