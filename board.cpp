/*
 * Patrick Bald
 * Class implementation 
 *
 */

#include <queue>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "board.h"
#include "gfx.h"

Board::Board(){


}

Board::~Board(){}

void Board::populate(){

	srand(time(0));
	for(int r = 0; r <= BOARDSIZE; r++){
		for(int c = 0; c <= BOARDSIZE; c++){
			dijkBoard[r][c] = rand()%20;
		}
	}

}

void Board::findPath(int startX, int startY, int endX, int endY){

	typedef pair<int, int> intPair;

	
}


void Board::displayPath(){}


