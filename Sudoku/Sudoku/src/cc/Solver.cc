#include <iostream>
#include "../header/Solver.h"
#include "../header/Sudoku.h"
#include "../header/utils.h"

bool SudokuSolver::IsValidPlacement(int board[][Sudoku::GRID_SIZE], int& row, int& column, int& number)
{
	return 
		!IsInRow(board, row, number) && 
		!IsInColumn(board, column, number) && 
		!IsIn3x3Square(board, row, column, number);
}

bool SudokuSolver::IsInRow(int board[][Sudoku::GRID_SIZE], int& row, int& number)
{
	for (int i = 0; i < Sudoku::GRID_SIZE; i++)
	{
		if (board[row][i] == number)
		{
			return true;
		}
	}
	return false;
}

bool SudokuSolver::IsInColumn(int board[][Sudoku::GRID_SIZE], int& column, int& number)
{
	for (int i = 0; i < Sudoku::GRID_SIZE; i++)
	{
		if (board[i][column] == number)
		{
			return true;
		}
	}
	return false;
}

bool SudokuSolver::IsIn3x3Square(int board[][Sudoku::GRID_SIZE], int& row, int& column, int& number)
{
	int top_row = row - row % 3;
	int left_column = column - column % 3;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (board[top_row + x][left_column + y] == number)
			{
				return true;
			}
		}
	}
	return false;
}

bool SudokuSolver::SolveBoard(int board[][Sudoku::GRID_SIZE])
{
	int x, y;
	if (!FindEmptySlot(board, x, y))
	{
		return true;
	}

	for (int i = 1; i < 10; i++)
	{
		if (IsValidPlacement(board, x, y, i))
		{
			board[x][y] = i;

			if (SolveBoard(board))
			{
				return true;
			}

			board[x][y] = 0;
		}
	}	

	return false;
}

bool SudokuSolver::FindEmptySlot(int board[][Sudoku::GRID_SIZE], int& row, int& column)
{
	for(row = 0; row < Sudoku::GRID_SIZE; row++)
	{
		for (column = 0; column < Sudoku::GRID_SIZE; column++)
		{
			if (board[row][column] == 0)
			{
				return true;
			}
		}
	}
	return false;
}
