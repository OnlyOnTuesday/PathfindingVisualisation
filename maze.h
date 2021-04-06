#pragma once
#include <iostream>
#include <stack>
using namespace std;

#include "olcConsoleGameEngine.h"
#include "state.h"

class Maze : public olcConsoleGameEngine
{
public:
	Maze();

	void generate();
	void draw();


private:
	int m_nMazeWidth;
	int m_nMazeHeight;
	state* m_maze;

	int m_nVisitedCells;
	stack<pair<int, int>> m_stack;
	int m_nPathWidth;


protected:
	virtual bool OnUserCreate()override;
	virtual bool OnUserUpdate(float fElapsedTime)override;

};
