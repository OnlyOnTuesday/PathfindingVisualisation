#ifndef MAZE_H
#define MAZE_H
#include colors.h

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

  //getters
  std::char getType();
  std::int getSize();

  //setters
  std::void setType(char type);
  std::void setSize(int size);

  //Check to see if next space is a wall or not
  std::bool isWall(int x, int y);
 private:

}

#endif
