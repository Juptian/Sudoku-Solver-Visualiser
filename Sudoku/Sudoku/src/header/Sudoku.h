#pragma once
// Lib files
#include <exception>

// Non-lib files
#include "Difficulty.h"

class Sudoku {

public:
	static const int GRID_SIZE = 9;
	int board[GRID_SIZE][GRID_SIZE];
	int initialBoard[GRID_SIZE][GRID_SIZE];

private:

	void CreateBoard(Difficulty);

public:
	Sudoku();
	Sudoku(Difficulty difficulty);
	Sudoku(int Board[][GRID_SIZE]);
};