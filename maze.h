#ifndef MAZE_H
#define MAZE_H

class maze
{
    public:
    maze(); //constructor
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
    block maze[dimensionX][dimensionX];
    int dimensionX = 10;
    int dimensionY = 10;

};
#endif