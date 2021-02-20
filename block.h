#ifndef BLOCK_H
#define BLOCK_H
#include colors.h
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

  //Check to see if next space is a wall or not
  std::bool isWall(int x, int y);
 private:
  char type = 'w'; //should be 'w' (wall) or 'p' (path)
                   //can add more options if we want later (e.g. what if the next path isn't
                   //set in stone?)
  int size = 0;

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
