#include "maze.h"
#include <iostream>

maze::maze(int x = 10, int y = 10)
{
    std::cout << "Intilizing maze: " << std::endl;
    setMazeDimensions(x, y);
    mazeArray = new Block[dimensionX][dimensionY];
    restart();
}
void maze::restart()
{
    callMazeGeneratingAlgorithm();
}
void maze::callMazeGeneratingAlgorithm()
{
    //whatever maze generaitng algorithm we want
    PrimAlgorithm();
}

void maze::setMazeDimensions(int x, int y)
{
    dimensionX = x;
    dimensionY = y;
}

int maze::getDimensionX() {
    return dimensionX;
}

int maze::getDimensionY() {
    return dimensionY;
}

void maze::PrimAlgorithm()
{
    //For Prim's Alg, the maze starts out as all walls
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            maze[x][y].setType('W'); // 'W' for wall
        }   
    }
    int startCellX = std::rand() % getDimensionX(); // random cell between 0 - dimensionX
    int startCellY = std::rand() % getDimensionY(); // random cell between 0 - dimensionY
    std::cout << startCellX << " " << startCellY << std::endl;

}
