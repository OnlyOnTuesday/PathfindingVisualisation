#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inp;
    inp.open("HelloWorldOutput.txt");
    string text;
    
    while(inp.good()){
        getline(inp, text);
        cout << text << endl;
    }
    return 0;
}
