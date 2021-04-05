build: main.o block.o maze.o
	g++ main.o block.o maze.o
main.o: main.cc
	g++ -c main.cc 
block.o: block.cpp block.h
	g++ -c block.cpp
maze.o: maze.h maze.cc
	g++ -c maze.cc

olc: block.cpp main.cc maze.cc olcPixelGameEngine.cpp
	 g++ main.cc block.cpp maze.cc olcPixelGameEngine.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs