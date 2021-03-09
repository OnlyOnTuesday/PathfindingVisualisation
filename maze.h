#ifndef MAZE_H
#define MAZE_H

#include "block.h"
class maze
{
    public:
    maze(int x = 10, int y = 10); //constructor
    void restart();
    void callMazeGeneratingAlgorithm();

    //MazeGenerating Algorithm
    void PrimAlgorithm();

    //Accessor
    int getDimensionX();
    int getDimensionY();
    //Mutator
    void setMazeDimensions();

    protected:
    int dimensionX;
    int dimensionY;
    Block *mazeArray;

};
#endif