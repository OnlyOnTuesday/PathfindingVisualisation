#include <iostream>
<<<<<<< HEAD
#include <fstream>
#include <string>

using namespace std;
=======
#include "maze.h"
>>>>>>> a8a6bd01080605f9b090fa2d61366da373c5f770

int main()
{
<<<<<<< HEAD
    Block helloworld;


=======
>>>>>>> 9df6dc1e41cfec553f2ca295cf68969898c525a0

    ifstream inp;
    inp.open("HelloWorldOutput.txt");
    string text;
    while(inp.good()){
        getline(inp, text);
        cout << text << endl;
    }
    return 0;
}
    
