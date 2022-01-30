#include <iostream>
#include <GLFW/glfw3.h>
#include "src/header/Sudoku.h"
#include "src/header/Solver.h"
#include "src/header/utils.h"

int main()
{
    // TODO:
    // * Make a board
    // * Make the algorithm to solve the sudoku
    // * Display the board
    // * Allow someone to actually play the game

    Sudoku sudoku;
    
    do
    {
        sudoku = Sudoku();
    }
    while (!SudokuSolver::SolveBoard(sudoku.board));

    PrintBoard(sudoku.board);

    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(640, 480, "Sudoku", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}