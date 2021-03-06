#ifndef MAZE_H
#define MAZE_H

class maze
{
    public:
    maze(); //constructor
    void restart();
    void callMazeGeneratingAlgorithm();

    protected:
    int maze[10][10];

};
#endif