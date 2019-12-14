/*
 * Patrick Bald
 * Fundamentals of Computing Fall 2019
 * Final Project
 * 12/12/19
 *
 * A c++, visual implementation of Dijkstra's shortest path algorithm
 *
 */

#include <iostream>
#include "board.h"

using namespace std;

#include "gfx2.h"

void welcome(int&, int&, int&, int&);

int main(){

	bool loop = true;

	gfx_open(wd, ht, "Dijkstra's");
	gfx_color(100, 0, 255);
	int startR = 200, startC = 200;
	for(int c = 0; c < BOARDSIZE; c++){
		for(int r = 0; r < BOARDSIZE; r++){
			gfx_color(100, 0, 255);
			gfx_fill_rectangle(startC + 50*c - offset, startR + 50*r - offset, l, l);
			gfx_color(0, 255, 0);
			gfx_point(startC + 50*c, startR + 50*r);
			gfx_flush();
		}
	}

	int startX, startY, endX, endY;

	welcome(startX, startY, endX, endY);
	gfx_color(255, 0, 0);
	gfx_fill_rectangle(startC + 50*endX - offset, startR + 50*endY - offset, l, l);
	gfx_flush();
	
	pair<int, int> start = make_pair(startX, startY);
	pair<int, int> end = make_pair(endX, endY);

	Board board;
	
	board.populate();
	int distance = board.findPath(start, end); // map < iPair, iPair >

	//board.displayBoard();
	//board.displayPath();

	cout << endl;
	cout << "The shortest distance from (" << startX << " , " << startY << ")";
	cout << " to "<< "( " << endX << " , " << endY << " )  is: " << distance << endl;
	
	//for(auto c : path){
	//	cout << (c.first).first << " " << (c.first).second << " " << (c.second).first << " " << (c.second).second << endl;
//	}

	

	return 0;
}

void welcome(int & startX, int & startY, int & endX, int & endY){
	
	cout << " ------------------------------- " << endl;
	cout << "    Welcome to shortest path!    " << endl;
	cout << " ------------------------------- " << endl;

	cout << "Enter a starting coordinate: ";
	cin >> startX >> startY;
	cout << endl;

	cout << "Enter an ending coordinate: ";
	cin >> endX >> endY;
	cout << endl;

}


