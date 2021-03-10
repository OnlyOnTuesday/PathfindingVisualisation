#ifndef MAZE_H
#define MAZE_H

#include "block.h"

class Maze
{
    public:
    Maze(); //constructor
    std::void restart();
    std::void callMazeGeneratingAlgorithm();

    /**
    * Should be in the maze class
    * @fn placeBlock
    * @param int x, x coordinate on grid
    * @param int y, y coordinate on grid
    * @return void
    */
    std::void placeBlock(int x, int y);
  
    std::void loadMaze(); 

    protected:
    int maze[10][10];

};
#endif
