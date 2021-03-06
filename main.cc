#include <iostream>
#include "block.h"

int main()
{
    Block helloworld;

    ifstream inp;
    inp.open("HelloWorldOutput.txt");
    string text;
    while(inp.good()){
        getline(inp, text);
        cout << text << endl;
    }
    return 0;
}
    
