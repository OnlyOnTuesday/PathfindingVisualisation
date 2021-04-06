#include "state.h"


state::state() {
	CELL_PATH_N = false;
	CELL_PATH_E = false;
	CELL_PATH_S = false;
	CELL_PATH_W = false;
	CELL_VISITED = false;
}

void state::visit()
{
	CELL_VISITED = true;
}


void state::set_Path_N()
{
	CELL_PATH_N = true;
}

void state::set_Path_E()
{
	CELL_PATH_E = true;
}

void state::set_Path_S()
{
	CELL_PATH_S = true;
}

void state::set_Path_W()
{
	CELL_PATH_W = true;
}

void state::clear()
{
	state();
}

bool state::get_Path_N()
{
	return CELL_PATH_N;
}

bool state::get_Path_E()
{
	return CELL_PATH_E;
}

bool state::get_Path_S()
{
	return CELL_PATH_S;
}

bool state::get_Path_W()
{
	return CELL_PATH_W;
}

bool state::get_visit()
{
	return CELL_VISITED;
}