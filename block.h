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

class Block
{
public:
    Block()
    {
    }

    //getters
    /**
    * @fn getType
    * @return a char that is either 'w' (wall) or 'p' (path)
    */
    std::char getType();

    //setters
    /**
    * @fn setType
    * @param char 'w' (wall) or 'p' (path)
    * @return void
    */
    std::void setType(char type);

    //Check to see if next space is a wall or not
    std::bool isWall(int x, int y);

private:
    char type = 'w'; //should be 'w' (wall) or 'p' (path)
                     //can add more options if we want later (e.g. what if the next path isn't
                     //set in stone?)
    int size = 0;

}

//currently being used to output our hello world
void
loadMaze()
{

    ifstream inp;
    inp.open("HelloWorldOutput.txt");
    std::string text;
    while (inp.good())
    {
        std::getline(inp, text);
        std::cout << text << std::endl;
    }
}

#endif
