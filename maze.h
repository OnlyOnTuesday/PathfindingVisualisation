#include <iostream>
#include <fstream>
#include <string>

class maze{

    void loadMaze();

    private:
    char maze = '#';

};

void loadMaze()
{
    ifstream inp;
    inp.open("HelloWorldMaze.txt");
    std::string text;
    while(!inp.good()){
        getline(inp, text);
        std::cout << text << std::endl;
    }
}
