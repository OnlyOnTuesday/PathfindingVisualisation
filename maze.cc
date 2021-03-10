#include "maze.h"

using namespace std;

Maze::maze()
{
    restart();
}
void Maze::restart()
{
    callMazeGeneratingAlgorithm();
}
void Maze::callMazeGeneratingAlgorithm()
{
    //whatever maze generaitng algorithm we want
}

void Maze::placeBlock(int x, int y){
    //how to place block on board
}

