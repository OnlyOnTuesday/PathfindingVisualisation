#ifndef BLOCK_H
#define BLOCK_H
#include "colors.h"
#include <string>
#include <fstream>

/*
 * different colors
 * each block should be a square that is 1 space
 * 
 * Needs to: placeBlock, 
 */

class Block {
public:

    Block() {
    }
    void placeBlock(int x, int y);
    void loadMaze();

    //getters

    /**
     * @fn getType
     * @return a char that is either 'w' (wall) or 'p' (path)
     */
    char getType();

    //setters
    /**
     * @fn setType
     * @param char 'w' (wall) or 'p' (path)
     * @return void
     */
    void setType(char c);

    //Check to see if next space is a wall or not
    bool isWall(int x, int y);
private:
    char type = 'w'; //should be 'w' (wall) or 'p' (path)
                     //can add more options if we want later (e.g. what if the next path isn't
                     //set in stone?)
    int size = 0;

};

#endif
