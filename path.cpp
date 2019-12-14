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

#include "gfx.h"

void welcome(int&, int&, int&, int&);

int main(){

	int startX, startY, endX, endY;

	welcome(startX, startY, endX, endY);
	
	pair<int, int> start = make_pair(startX, startY);
	pair<int, int> end = make_pair(endX, endY);

	Board board;
	
	board.populate();
	map< iPair, iPair> path = board.findPath(start, end);
	board.displayBoard();
	//board.displayPath();

	cout << endl;
//	cout << "The shortest distance from (" << startX << " , " << startY << ")";
//	cout << " to "<< "( " << endX << " , " << endY << " )  is: " << distance << endl;
	
	//while( ){}

	return 0;
}

void welcome(int & startX, int & startY, int & endX, int & endY){
	
	cout << " ------------------------------- " << endl;
	cout << " 	 Welcome to shortest path!    " << endl;
	cout << " ------------------------------- " << endl;

	cout << "Enter a starting coordinate: ";
	cin >> startX >> startY;
	cout << endl;

	cout << "Enter an ending coordinate: ";
	cin >> endX >> endY;
	cout << endl;

}


