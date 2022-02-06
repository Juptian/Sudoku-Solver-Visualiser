#include <iostream>
#include <chrono>
#include "../header/Sudoku.h"
#include "../header/Solver.h"

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

void Benchmark(int board[][Sudoku::GRID_SIZE], int trials)
{
    Sudoku sudoku = Sudoku(board);

    SudokuSolver solver = SudokuSolver();
    
    std::chrono::nanoseconds time = std::chrono::nanoseconds();
    
    long* timingsUs = new long[trials];

    for (int i = 0; i < trials; i++)
    {        
        memcpy(sudoku.board, board, sizeof(board));
        auto start = std::chrono::steady_clock::now();
        solver.SolveBoard(sudoku.board);
        auto end = std::chrono::steady_clock::now();

        timingsUs[i] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    long sum = 0;
    for (int i = 0; i < trials; i++)
    {
        sum += timingsUs[i];
    }

    auto average = sum / (double)trials;

    std::cout << trials << " solves in " << sum << " nanoseconds\n";
    std::cout << average << "us average\n";
    PrintBoard(sudoku.board);
}