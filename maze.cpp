
#include <iostream>
#include <stack>
#include "maze.h"
#include "state.h"

// Define our static variables
std::atomic<bool> olcConsoleGameEngine::m_bAtomActive(false);
std::condition_variable olcConsoleGameEngine::m_cvGameFinished;
std::mutex olcConsoleGameEngine::m_muxGame;

Maze::Maze()
{
	m_sAppName = L"MAZE";
}

bool Maze::OnUserCreate()
{
	// Maze Parameters
	m_nMazeWidth = 40;
	m_nMazeHeight = 25;

	m_maze = new state[m_nMazeWidth * m_nMazeHeight];

	memset(m_maze, 0x00, m_nMazeWidth * m_nMazeHeight * sizeof(int));

	m_stack.push(make_pair(0, 0));
	m_maze[0].visit();
	m_nVisitedCells = 1;

	m_nPathWidth = 3;

	//srand(time(0));
	mazeSolved = false;

	return true;
}

bool Maze::OnUserUpdate(float fElapsedTime)
{

	if (m_nVisitedCells < m_nMazeHeight * m_nMazeWidth) {
		generate();
	}
	else { // maze has been successfully generated
		if (nCall == 0) {
			m_stack.pop();
			m_stack.push(make_pair(0, 0));
			m_maze[0].set_Solved();
			nCall++;
		}
		bool mazeSolved = solver();
	}


	// == Drawing Stuff == 
	// Clear Screen 
	Fill(0, 0, m_nScreenWidth, m_nScreenHeight, L' ');

	// Draw the maze
	draw();



	return true;
}

void Maze::generate()
{
	// Step 1: Create a set of unvisited neighbors
	auto offset = [&](int x, int y) {
		return (m_stack.top().second + y) * m_nMazeWidth + (m_stack.top().first + x);
	};


	vector<int> neighbors;

	// North Neightbor
	if (m_stack.top().second > 0 && (!m_maze[offset(0, -1)].get_visit()))
		neighbors.push_back(0);

	// East Neightbor
	if (m_stack.top().first < m_nMazeWidth - 1 && (!m_maze[offset(1, 0)].get_visit()))
		neighbors.push_back(1);

	// South Neighbor
	if (m_stack.top().second < m_nMazeHeight - 1 && (!m_maze[offset(0, 1)].get_visit()))
		neighbors.push_back(2);

	// West Neighbor
	if (m_stack.top().first > 0 && (!m_maze[offset(-1, 0)].get_visit()))
		neighbors.push_back(3);

	// Are there any neighbors avail?
	if (!neighbors.empty()) {
		//choose one available neighbor at random
		int next_cell_dir = neighbors[rand() % neighbors.size()];

		// Create a path between the neighbor and the current cell
		switch (next_cell_dir) {

		case 0: // North 
			m_maze[offset(0, -1)].visit();
			m_maze[offset(0, -1)].set_Path_S();
			m_maze[offset(0, 0)].set_Path_N();
			m_stack.push(make_pair((m_stack.top().first + 0), (m_stack.top().second - 1)));
			break;

		case 1: // East
			m_maze[offset(+1, 0)].visit();
			m_maze[offset(+1, 0)].set_Path_W();
			m_maze[offset(0, 0)].set_Path_E();
			m_stack.push(make_pair((m_stack.top().first + 1), (m_stack.top().second + 0)));
			break;

		case 2: // South
			m_maze[offset(0, +1)].visit();
			m_maze[offset(0, +1)].set_Path_N();
			m_maze[offset(0, 0)].set_Path_S();
			m_stack.push(make_pair((m_stack.top().first + 0), (m_stack.top().second + 1)));
			break;

		case 3: // West
			m_maze[offset(-1, 0)].visit();
			m_maze[offset(-1, 0)].set_Path_E();
			m_maze[offset(0, 0)].set_Path_W();
			m_stack.push(make_pair((m_stack.top().first - 1), (m_stack.top().second + 0)));
			break;

		}
		// new cell
		m_nVisitedCells++;
	}
	else {
		m_stack.pop(); // Backtrack
	}

}

void Maze::draw()
{
	for (int x = 0; x < m_nMazeWidth; x++) {
		for (int y = 0; y < m_nMazeHeight; y++) {
			for (int py = 0; py < m_nPathWidth; py++) {
				for (int px = 0; px < m_nPathWidth; px++) {
					if (m_maze[y * m_nMazeWidth + x].get_visit()) {
						if (x == m_stack.top().first && y == m_stack.top().second) {
							Draw(x * (m_nPathWidth + 1) + px, y * (m_nPathWidth + 1) + py, PIXEL_SOLID, FG_GREEN);
						}
						else if (x == 0 && y == 0) {
							Draw(x * (m_nPathWidth + 1) + px, y * (m_nPathWidth + 1) + py, PIXEL_SOLID, FG_RED);
						}
						else if (x == m_nMazeWidth - 1 && y == m_nMazeHeight - 1) {
							Draw(x * (m_nPathWidth + 1) + px, y * (m_nPathWidth + 1) + py, PIXEL_SOLID, FG_RED);
						}
						else if (m_maze[y * m_nMazeWidth + x].get_Solved()) {
							Draw(x * (m_nPathWidth + 1) + px, y * (m_nPathWidth + 1) + py, PIXEL_SOLID, FG_DARK_YELLOW);
						}
						else
							Draw(x * (m_nPathWidth + 1) + px, y * (m_nPathWidth + 1) + py, PIXEL_SOLID, FG_WHITE);
					}
					else {
						Draw(x * (m_nPathWidth + 1) + px, y * (m_nPathWidth + 1) + py, PIXEL_SOLID, FG_BLUE);
					}
				}
			}
			for (int p = 0; p < m_nPathWidth; p++) {
				if (m_maze[y * m_nMazeWidth + x].get_Path_S()) {
					Draw(x * (m_nPathWidth + 1) + p, y * (m_nPathWidth + 1) + m_nPathWidth);
				}
				if (m_maze[y * m_nMazeWidth + x].get_Path_E()) {
					Draw(x * (m_nPathWidth + 1) + m_nPathWidth, y * (m_nPathWidth + 1) + p);
				}
			}
		}
	}
}






// maze solving algs

bool Maze::solver(char c) {
	if (c == 'A') {
		return wallFollower();
	}
}

bool Maze::wallFollower() 
{


	// step 1 is to get potential neighbors
	auto offset = [&](int x, int y) {
		return (m_stack.top().second + y) * m_nMazeWidth + (m_stack.top().first + x);
	};

	if (offset(0, 0) == m_nMazeHeight * m_nMazeWidth - 1) { // have we reached the end??
		return true;
	}



	vector<int> neighbors;
	bool go_west = false;
	bool go_south = false;


	// North Neightbor
	if (m_stack.top().second > 0 && (m_maze[offset(0, -1)].get_Path_S() && !m_maze[offset(0, -1)].get_Solved()) )
		neighbors.push_back(0);

	// East Neightbor
	if (m_stack.top().first < m_nMazeWidth - 1 && (m_maze[offset(1, 0)].get_Path_W() && !m_maze[offset(1, 0)].get_Solved()))
		neighbors.push_back(1);

	// South Neighbor
	if (m_stack.top().second < m_nMazeHeight - 1 && (m_maze[offset(0, 1)].get_Path_N() && !m_maze[offset(0, 1)].get_Solved())) {
		neighbors.push_back(2);
		go_south = true;
	}
	// West Neighbor
	if (m_stack.top().first > 0 && (m_maze[offset(-1, 0)].get_Path_E() && !m_maze[offset(-1, 0)].get_Solved())) {
		neighbors.push_back(3);
		go_west = true;
	}
	// Are there any neighbors avail?
	if (!neighbors.empty()) {
		//choose one available neighbor at random
		//int next_cell_dir = neighbors[rand() % neighbors.size()];
		int next_cell_dir;
		if (go_west)
			next_cell_dir = 3;
		else if (go_south)
			next_cell_dir = 2;
		else
			next_cell_dir = neighbors[rand() % neighbors.size()];


		// Create a path between the neighbor and the current cell
		switch (next_cell_dir) {

		case 0: // North 
			m_maze[offset(0, -1)].set_Solved();
			m_stack.push(make_pair((m_stack.top().first + 0), (m_stack.top().second - 1)));
			break;

		case 1: // East
			m_maze[offset(+1, 0)].set_Solved();
			m_stack.push(make_pair((m_stack.top().first + 1), (m_stack.top().second + 0)));
			break;

		case 2: // South
			m_maze[offset(0, +1)].set_Solved();
			m_stack.push(make_pair((m_stack.top().first + 0), (m_stack.top().second + 1)));
			break;

		case 3: // West
			m_maze[offset(-1, 0)].set_Solved();
			m_stack.push(make_pair((m_stack.top().first - 1), (m_stack.top().second + 0)));
			break;

		}
	}
	else {
		m_stack.pop(); // Backtrack
	}

	return false;
}