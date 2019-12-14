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

void Board::displayBoard(){
	for(int c = 0; c < BOARDSIZE; c++){
		for(int r = 0; r < BOARDSIZE; r++){
			cout << setw(5) << left << b[c][r];
		}
		cout << endl;
	}

}

int  Board::findPath( iPair start, iPair end ){ // map <iPair, iPair> 

	set< iPair > visited; // keep track of visited locations
	//map< iPair, iPair > path; // now global 
	
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
				//addToPath(loc, n);
				distance[n.first][n.second] = distance[loc.first][loc.second] + b[n.first][n.second];
				pq.push(make_pair(distance[n.first][n.second], n));
			}
		}

		gfx_color(100, 0, 255);
		gfx_fill_rectangle(50*loc.first + 220 - offset, 50*loc.second + 220 - offset, l, l);
		char buffer[16];
		int weight = b[loc.first][loc.second];
		sprintf(buffer, "%d", weight);
		gfx_color(255, 0, 0);
		gfx_text(49*loc.first + 220, 51*loc.second + 220, buffer);
		gfx_flush();
		usleep(20000);
	}

	return distance[end.first][end.second];
}

set < iPair > Board::getNeighbors(iPair loc){

	set <iPair > neighbors;
	
	//location.first = columns
	//location.second = rows
	if(loc.first != BOARDSIZE - 1) neighbors.insert(make_pair(loc.first + 1, loc.second)); // right neighbor
	if(loc.first != 0) neighbors.insert(make_pair(loc.first - 1, loc.second)); // left
	if(loc.second != BOARDSIZE - 1) neighbors.insert(make_pair(loc.first, loc.second + 1)); // below 
	if(loc.second != 0) neighbors.insert(make_pair(loc.first, loc.second - 1)); // above

	return neighbors;

}

void Board::addToPath(iPair loc, iPair n){
	//path{n} = loc;
}

map< iPair, iPair > Board::getPath(){ return path; }

void Board::displayPath(){
	cout << "Vertex	" << "Distance" << endl;
	for(int c = 0; c < BOARDSIZE; c++){
		for(int r = 0; r < BOARDSIZE; r++){
			cout << c << " " << r << " 	" << distance[c][r] << endl;
		}
	}

}
