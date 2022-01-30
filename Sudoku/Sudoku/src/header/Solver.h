#pragma once
#include "Sudoku.h"

class SudokuSolver 
{
public:
	static bool IsValidPlacement(int board[][Sudoku::GRID_SIZE], int& row, int& column, int& number);
	static bool IsInRow(int board[][Sudoku::GRID_SIZE], int& row, int&number);
	static bool IsInColumn(int board[][Sudoku::GRID_SIZE],  int& column, int& number);
	static bool IsIn3x3Square(int board[][Sudoku::GRID_SIZE], int& row, int& column, int& number);
	static bool SolveBoard(int board[][Sudoku::GRID_SIZE]);
	static bool FindEmptySlot(int board[][Sudoku::GRID_SIZE], int& row, int& column);
};
