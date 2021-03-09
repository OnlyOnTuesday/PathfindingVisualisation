#ifndef MAZE_H
#define MAZE_H

#include "block.h"
class Maze
{
    public:
    Maze(int x = 10, int y = 10); //constructor
    void restart();
    void callMazeGeneratingAlgorithm();

    //MazeGenerating Algorithm
    void PrimAlgorithm();

    //Accessor
    int getDimensionX();
    int getDimensionY();
    //Mutator
    void setMazeDimensions(int x, int y);

    private:
    int dimensionX;
    int dimensionY;
    Block **maze;

};
#endif