#pragma once
#include <iostream>
#include "Sudoku.h"
#define uint unsigned int

void PrintBoard(int board[][Sudoku::GRID_SIZE]);
void Benchmark(int board[][Sudoku::GRID_SIZE], int trials);
