#ifndef MAZE_H
#define MAZE_H
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

  Block(){
  }
  std::void placeBlock(int x, int y);
  void loadMaze();

  //getters
  std::char getType();
  std::int getSize();

  //setters
  std::void setType(char type);
  std::void setSize(int size);

  //Check ot see if next space is a wall or not
  std::bool isWall(int x, int y);
 private:

}
void loadMaze(){

    ifstream inp;
    inp.open("HelloWorldOutput.txt");
    std::string text;
    while(inp.good()){
        std::getline(inp, text);
        std::cout << text << std::endl;
    }
}


#endif
