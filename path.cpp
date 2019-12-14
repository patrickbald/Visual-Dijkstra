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
void start(int&, int&, int&, int&);

int main(){

	bool loop = true;
	char c;
	int distance;
	int startX, startY, endX, endY;

	gfx_open(wd, ht, "Dijkstra's");
	
	cout << " ------------------------------- " << endl;
	cout << "    Welcome to shortest path!    " << endl;
	cout << " ------------------------------- " << endl;

	gfx_text(250, 100, "Visual representation of Dijkstra's algorithm");
	//start(startX, startY, endX, endY);	

	//welcome(startX, startY, endX, endY);
	//gfx_color(255, 0, 0);
	//gfx_fill_rectangle(startC + 50*endX - offset, startR + 50*endY - offset, l, l);
	//gfx_flush();
	
	//pair<int, int> start = make_pair(startX, startY);
	//pair<int, int> end = make_pair(endX, endY);

	Board board; // Board object
	//board.populate(); // fill in weights of board 
	while(loop) {
		c = gfx_wait();
		if(c == ' '){
			start(startX, startY, endX, endY);
			pair<int, int> start = make_pair(startX, startY);
			pair<int, int> end = make_pair(endX, endY);
			board.populate();
			distance = board.findPath(start, end); // map < iPair, iPair >
			board.displayBoard();
			cout << endl;
			cout << "The shortest distance from (" << startX << " , " << startY << ")";
			cout << " to "<< "( " << endX << " , " << endY << " )  is: " << distance << endl;
		} else if(c == 'q')
			break;
	}
	//board.displayBoard();

	//cout << endl;
	//cout << "The shortest distance from (" << startX << " , " << startY << ")";
	//cout << " to "<< "( " << endX << " , " << endY << " )  is: " << distance << endl;
	
	return 0;
}

void welcome(int & startX, int & startY, int & endX, int & endY){
	

	cout << "Enter a starting coordinate: ";
	cin >> startX >> startY;
	cout << endl;

	cout << "Enter an ending coordinate: ";
	cin >> endX >> endY;
	cout << endl;

}

void start(int & startX, int & startY, int & endX, int & endY){
	gfx_color(100, 0, 255);
	int startR = 200, startC = 200;
	for(int c = 0; c < BOARDSIZE; c++){
		for(int r = 0; r < BOARDSIZE; r++){
			gfx_fill_rectangle(startC + 50*c - offset, startR + 50*r - offset, l, l);
			gfx_flush();
		}
	}

	welcome(startX, startY, endX, endY);
	gfx_color(255, 0, 0);
	gfx_fill_rectangle(startC + 50*endX - offset, startR + 50*endY - offset, l, l);
	gfx_flush();
}
