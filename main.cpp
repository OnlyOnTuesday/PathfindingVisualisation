#include <iostream>
#include <stack>
#include "maze.h"
#include "olcConsoleGameEngine.h"

int main()
{
	Maze game;
	game.ConstructConsole(160, 100, 8, 8);
	game.Start();
	return 0;
}