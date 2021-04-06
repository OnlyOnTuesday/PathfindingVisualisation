#pragma once


class state
{
public:
	state();

	// mutators
	void visit();
	void set_Path_N();
	void set_Path_E();
	void set_Path_S();
	void set_Path_W();
	void clear();

	// accessors
	bool get_Path_N();
	bool get_Path_E();
	bool get_Path_S();
	bool get_Path_W();
	bool get_visit();

private:
	bool CELL_PATH_N;
	bool CELL_PATH_E;
	bool CELL_PATH_S;
	bool CELL_PATH_W;
	bool CELL_VISITED;

};
