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

void getCoordinates(int&, int&, int&, int&, Board &);
void start(int&, int&, int&, int&, Board &);
void dispInstructions();
void dispScore(int);

int main(){

	bool loop = true;
	char c;
	int distance;
	int startX, startY, endX, endY;

	gfx_open(wd, ht, "Dijkstra's");
	
	dispInstructions();

	while(loop) {
		c = gfx_wait();
		gfx_clear();
		if(c == ' '){
			Board board;
			board.populate();
			start(startX, startY, endX, endY, board);
			iPair start = make_pair(startX, startY);
			iPair end = make_pair(endX, endY);
			distance = board.findPath(start, end); // map < iPair, iPair >
			dispScore(distance);
		} else if(c == 'q')
			break;
	}
	
	return 0;
}

void getCoordinates(int & startX, int & startY, int & endX, int & endY, Board & board){
	char c;

	board.dispAllWeights();

	c = gfx_wait();
	startX = c - '0';
	c = gfx_wait();
	startY = c - '0';
	gfx_color(0, 255, 0);
	gfx_fill_rectangle(startC + 50*startX - offset, startR + 50*startY - offset, l, l);
	c = gfx_wait();
	endX = c - '0';
	c = gfx_wait();
	endY = c - '0';
	gfx_color(255, 0, 0);
	gfx_fill_rectangle(startC + 50*endX - offset, startR + 50*endY - offset, l, l);
	gfx_flush();
	
}

void start(int & startX, int & startY, int & endX, int & endY, Board & board){
	gfx_color(0, 0, 252);
	for(int c = 0; c < BOARDSIZE; c++){
		for(int r = 0; r < BOARDSIZE; r++){
			gfx_fill_rectangle(startC + 50*c - offset, startR + 50*r - offset, l, l);
			gfx_flush();
		}
	}

	for(int c = 0; c < 8; c++){
		char buffer[16];
		sprintf(buffer, "%d", c);
		gfx_color(255, 255, 255);
		gfx_text(170, (l+2)*c + 220, buffer);
	}

	for(int r = 0; r < 8; r++){
		char buffer[16];
		sprintf(buffer, "%d", r);
		gfx_color(255, 255, 255);
		gfx_text(220 + (l+2)*r, 180, buffer);
	}

	gfx_color(255, 255, 255);		
	dispInstructions();

	getCoordinates(startX, startY, endX, endY, board);
}

void dispInstructions(){
	gfx_text(250, 80, "Visual representation of Dijkstra's algorithm");
	gfx_text(220, 100, "Press space to build board initially and after every run");
	gfx_text(180, 120, "After building board, enter 4 integers for shortest path coordinates");
	gfx_text(350, 140, "Press Q to exit");
}

void dispScore(int distance){
	char buffer[16];
	sprintf(buffer, "%d", distance);
	gfx_color(255, 255, 255);
	gfx_text(240, 630, "The shortest path from start to finish is: ");
	gfx_text(520, 630, buffer);

}
