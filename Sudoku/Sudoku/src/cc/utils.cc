#include <iostream>
#include "../header/Sudoku.h"

void PrintBoard(int board[][Sudoku::GRID_SIZE])
{
	std::cout << "|-------|-------|-------|\n";

	for (int x = 0; x < Sudoku::GRID_SIZE; x++)
	{
		for (int y = 0; y < Sudoku::GRID_SIZE; y++)
		{
			if (y == 0)
			{
				std::cout << "| ";
			}

			std::cout << board[x][y] << " ";
			if (y % 3 == 2)
			{
				std::cout << "| ";
			}
		}
		std::cout << "\n";
		if (x % 3 == 2)
		{
			std::cout << "|-------|-------|-------|\n";
		}
	}
	std::cout << "\n";
}