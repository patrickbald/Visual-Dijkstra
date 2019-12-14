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

map <iPair, iPair> Board::findPath( iPair start, iPair end ){
	
	set< iPair > visited; // keep track of visited locations
	map< iPair, iPair > path;
	
	// start.first = column, start.second = row 
	distance[start.first][start.second] = b[start.first][start.second];
	
	// keep track of smallest neightbors that alg will visit
	priority_queue< pPair, vector< pPair >, greater< pPair > > pq; 
	
	// put start location and weight in queue
	pq.push(make_pair(b[start.first][start.second], start));
	
	while(!pq.empty()){ 
		
		iPair loc = pq.top().second; // current location
		pq.pop();

		// skip locations have already been too
		if (visited.find(loc) != visited.end()) continue; 
		visited.insert(loc);

		for(auto n : getNeighbors(loc)){
			if(distance[loc.first][loc.second] + b[n.first][n.second] < distance[n.first][n.second]){
				path{n} = loc;
				distance[n.first][n.second] = distance[loc.first][loc.second] + b[n.first][n.second];
				pq.push(make_pair(distance[n.first][n.second], n));
			}
		}
	}

	//return distance[end.first][end.second];
	return path;

}

// get neighbors method
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

void Board::displayPath(){
	
	cout << "Vertex	" << "Distance" << endl;
	for(int c = 0; c < BOARDSIZE; c++){
		for(int r = 0; r < BOARDSIZE; r++){
			cout << c << " " << r << " 	" << distance[c][r] << endl;
		}
	}

}


	/// @TODO: Remove
	/*
	set <pair <int, int> > s;
	s.insert(make_pair(1, 10));
	if (s.find(make_pair(1, 10)) != s.end()) cout << "FOUND!!!" << endl;
	if (s.find(make_pair(1, 5)) != s.end()) cout << "FOUND SECOND!!!" << endl;
	*/
