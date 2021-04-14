#include <iostream>
#include <fstream>
#include <cassert>
#include <stack>
#include "maze.h"
#include "olcConsoleGameEngine.h"

//recursive function actually solves it
bool solver(int maze[4][4], int x, int y, int solved[4][4]);
//print solution
void print(int solved[4][4]);
//checks to see if move is allowed
bool safeMove(int maze[4][4], int x, int y);
//calls solver with simple input
bool solveIt(int maze[4][4]);

int main()
{
 //   int a_maze[4][4] = { { 1, 1, 1, 1},
 //                      { 1, 1, 0, 1},
 //                    { 0, 1, 0, 0},
 //                      { 1, 1, 1, 1} };
 //   for(int i = 0; i < 4; i++){
 //       for(int j = 0; j < 4; j++)
 //           std::cout << a_maze[i][j] << " ";
 //       std::cout << std::endl;
 //   }
//	std::cout << std::endl;
//    assert(solveIt(a_maze)==true);

//	std::cout << std::endl;
	
//	int b_maze[4][4] = { { 1, 1, 1, 1},
 //                      { 1, 1, 0, 1},
 //                      { 0, 1, 0, 0},
 //                      { 1, 1, 0, 1} };
 //   for(int i = 0; i < 4; i++){
 //       for(int j = 0; j < 4; j++)
 //           std::cout << b_maze[i][j] << " ";
 //       std::cout << std::endl;
 //   }				   
//	std::cout << std::endl;
//	assert(solveIt(b_maze)==true);

    Maze game;
    game.ConstructConsole(160, 100, 8, 8);
    game.Start();
    return 0;
};

bool solveIt(int maze[4][4]){
    //solution to be built
    int solved[4][4] = { { 0, 0, 0, 0},
                       { 0, 0, 0, 0},
                       { 0, 0, 0, 0},
                       { 0, 0, 0, 0} };
    //checks to see if there is a solution and solves it at the same time
    if(solver(maze, 0, 0, solved) == false){
        std::cout << "No Solution" << std::endl;
        return false;
    }
    //print the solution
    print(solved);
    return true;
};

bool safeMove(int maze[4][4], int x, int y){
    //are the coordinates in bounds?
    if(x >= 0 && x < 4 && y >= 0 && y < 4 && maze[x][y] == 1)
        return true;
    return false;
};

void print(int solved[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
            std::cout << solved[i][j] << " ";
        std::cout << std::endl;
    }
};

bool solver(int maze[4][4], int x, int y, int solved[4][4]){
    //at the end of the maze and its solvable
    if(x == 3 && y == 3 && maze[x][y] == 1){
        solved[x][y] = 1;
        return true;
    }
    //is it a valid move?
    if(safeMove(maze, x, y)){
        //its solved
        if(solved[x][y] == 1)
            return false;
        //mark the map
        solved[x][y] = 1;

        //check to the right
        if(solver(maze, x+1, y, solved))
            return true;
        //check down
        if(solver(maze, x, y+1, solved))
            return true;
        //check left
        if(solver(maze, x-1, y, solved))
            return true;
        //check up
        if(solver(maze, x, y-1, solved))
            return true;
        //that's a
        solved[x][y] = 0;
        return false;
    }
    return false;
};