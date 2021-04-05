#include "maze.h"


using namespace std;

#include <iostream>
#include <ctime>
Maze::Maze(int x , int y )

{
    std::cout << "Initializing maze: " << std::endl;
    setMazeDimensions(x, y);
    // mazeArray = new Block[dimensionX][dimensionY];
    maze = new Block*[dimensionX];
    for(int i = 0; i < dimensionX; ++i){
        maze[i] = new Block[dimensionY];
    }
    restart();
}
void Maze::restart()
{
    callMazeGeneratingAlgorithm();
}
void Maze::callMazeGeneratingAlgorithm()
{
    //whatever maze generaitng algorithm we want
    PrimAlgorithm();
}

void Maze::setMazeDimensions(int x, int y)
{
    dimensionX = x;
    dimensionY = y;
}

int Maze::getDimensionX() {
    return dimensionX;
}

int Maze::getDimensionY() {
    return dimensionY;
}

void Maze::PrimAlgorithm()
{
    //For Prim's Alg, the maze starts out as all walls
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            maze[x][y].setType('W'); // 'W' for wall
        }   
    }
    std::srand(std::time(NULL)); //use time to randomly seed random # generator
    int startCellX = std::rand() % getDimensionX(); // random cell between 0 - dimensionX
    int startCellY = std::rand() % getDimensionY(); // random cell between 0 - dimensionY
    std::cout << startCellX << " " << startCellY << std::endl;

}

// void Maze::placeBlock(int x, int y){
//     //how to place block on board
// }

