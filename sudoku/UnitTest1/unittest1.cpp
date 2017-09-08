#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sudoku/SudokuPlayer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			//SudokuPlayer sudokuPlayer;
			//sudokuPlayer.playSudoku(1);

			add add;
			int x = 1, y = 2, result = 3;
			Assert::AreEqual(add.addNumber(x, y), result);
		}

	};
}