#include <random>
#include "../header/Sudoku.h"
#include "../header/Difficulty.h"
#include "../header/Solver.h"
#include <iostream>

Sudoku::Sudoku()
	: Sudoku(Difficulty::EASY)
{}

Sudoku::Sudoku(Difficulty difficulty)
{
	memset(board, 0, sizeof(board));
	CreateBoard(difficulty);
}

void Sudoku::CreateBoard(Difficulty difficulty)
{
	int total_slots = GRID_SIZE * GRID_SIZE;
	// 21 so that on the EASY difficulty, you get 20/81 slots filled in
	int slotsToFill = 22 - int(difficulty) * 2;
	
	for (int i = 0; i < slotsToFill; i++)
	{
		int row, column, number;
		do
		{
			row = rand() % 9;
			column = rand() % 9;
			number = rand() % 9 + 1;
		}
		while (!SudokuSolver::IsValidPlacement(board, row, column, number));
		board[row][column] = number;
	}
}

