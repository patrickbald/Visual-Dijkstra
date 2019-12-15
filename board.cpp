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
#include <iostream>
#include "gfx2.h"
#include <climits>
#include <algorithm>
#include <set>
#include <utility>
#include <iomanip>
#include <map>
#include <unistd.h>

Board::Board(){

	initDistance();

}

Board::~Board(){}

void Board::initDistance(){
	for(int c = 0; c < BOARDSIZE; c++){
		for(int r = 0; r < BOARDSIZE; r++){
			distance[c][r] = INT_MAX;
		}
	}

}

void Board::populate(){
	srand(time(0));
	for(int c = 0; c < BOARDSIZE; c++){
		for(int r = 0; r < BOARDSIZE; r++){
			b[c][r] = rand()%20 + 1;
		}
	}

}

int  Board::findPath( iPair start, iPair end ){ 

	dispAllWeights();
	
	set< iPair > visited; // keep track of visited locations
	
	// start.first = column, start.second = row 
	distance[start.first][start.second] = b[start.first][start.second];
	
	// keep track of smallest neightbors that alg will visit
	priority_queue< pPair, vector< pPair >, greater< pPair > > pq; 
	
	// put start location and weight in queue
	pq.push(make_pair(b[start.first][start.second], start));
	
	while(!pq.empty()){ 
		
		iPair loc = pq.top().second; // current location
		pq.pop();
		
		gfx_color(0, 255, 0);
		gfx_fill_rectangle(50*loc.first + 220 - offset, 50*loc.second + 220 - offset, l, l);
		gfx_flush();
		usleep(20000);

		// skip locations have already been too
		if (visited.find(loc) != visited.end()) continue; 
		visited.insert(loc);

		for(auto n : getNeighbors(loc)){
			if(distance[loc.first][loc.second] + b[n.first][n.second] < distance[n.first][n.second]){
				addToPath(loc, n);
				distance[n.first][n.second] = distance[loc.first][loc.second] + b[n.first][n.second];
				pq.push(make_pair(distance[n.first][n.second], n));
			}
		}
		// change rectangle back to original color
		//gfx_color(100, 0, 255);
		//gfx_fill_rectangle(50*loc.first + 220 - offset, 50*loc.second + 220 - offset, l, l);

		// print out weight of current vertex
		gfx_color(255, 0, 0);
		drawWeight(loc);

		displayInstructions();

		gfx_flush();
	}

	//	traverse map and color in the path
	iPair current = end;
	while(current != start){
		gfx_color(255, 0, 0);
		gfx_fill_rectangle(current.first*50 + 220 - offset, current.second*50 + 220 - offset, l, l);
		drawWeight(current);
		current = path[current];
	}
	
	// color in first node 	
	gfx_color(255, 0, 0);
	gfx_fill_rectangle(current.first*50 + 220 - offset, current.second*50 + 220 - offset, l, l);
	drawWeight(current);
	return distance[end.first][end.second];
}

void Board::drawWeight(iPair loc){
	char buffer[16];
	int weight = b[loc.first][loc.second];
	sprintf(buffer, "%d", weight);
	gfx_color(255, 255, 255);
	gfx_text(49*loc.first + 220, 51*loc.second + 220, buffer);

}

set < iPair > Board::getNeighbors(iPair loc){
	set <iPair > neighbors;
	
	//location.first = columns
	//location.second = rows
	if(loc.first != BOARDSIZE - 1) neighbors.insert(make_pair(loc.first + 1, loc.second)); // right 
	if(loc.first != 0) neighbors.insert(make_pair(loc.first - 1, loc.second)); // left
	if(loc.second != BOARDSIZE - 1) neighbors.insert(make_pair(loc.first, loc.second + 1)); // below 
	if(loc.second != 0) neighbors.insert(make_pair(loc.first, loc.second - 1)); // above

	return neighbors;

}

void Board::addToPath(iPair loc, iPair n){
	path[n] = loc;
}

void Board::displayInstructions(){
		gfx_color(255, 255, 255);
		gfx_text(250, 80, "Visual representation of Dijkstra's algorithm");
		gfx_text(220, 100, "Press space to build board initially and after every run");
		gfx_text(180, 120, "After building board, enter 4 integers for shortest path coordinates");
		gfx_text(350, 140, "Press Q to exit");

}

void Board::dispAllWeights(){
	for(int c = 0; c < BOARDSIZE; c++){
		for(int r = 0; r < BOARDSIZE; r++){
			char buffer[16];
			int weight = b[c][r];
			sprintf(buffer, "%d", weight);
			gfx_color(255, 255, 255);
			gfx_text(49*c + 220, 51*r + 220, buffer);
		}
	}

}
