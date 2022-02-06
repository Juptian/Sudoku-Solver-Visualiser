#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include "src/header/Sudoku.h"
#include "src/header/Solver.h"
#include "src/header/utils.h"
#include "src/header/VertexBuffer.h"
int main()
{
    // TODO:
    // * Make a board
    // * Make the algorithm to solve the sudoku
    // * Display the board
    // * Allow someone to actually play the game

    Sudoku sudoku = Sudoku();
    auto board = new int[][Sudoku::GRID_SIZE] {
        { 0,7,0,2,0,0,0,0,3 },
        { 4,0,0,8,0,0,7,0,0 },
        { 0,1,3,0,0,0,0,0,0 },
        { 5,0,0,9,0,0,4,0,0 },
        { 7,0,0,0,2,0,0,6,0 },
        { 0,0,0,0,0,0,0,0,0 },
        { 2,0,0,0,5,0,9,0,0 },
        { 1,0,5,0,6,0,0,0,4 },
        { 0,0,0,0,1,0,3,0,0 }
    };

    Benchmark(board, 100000);

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

    if (glewInit() != GLEW_OK)
    {
        std::cout << "GLEW is not ok someone send it some help\n";
    }

    std::cout << "OpenGL version" << glGetString(GL_VERSION) << "\n";

    float points[6] = {
        -0.5f, 0.f,
        -0.5f, -0.5f,
        0.5f, -0.5f
    };


    while (!glfwWindowShouldClose(window))
    {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);



        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for events and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}