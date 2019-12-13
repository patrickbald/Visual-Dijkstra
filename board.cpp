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
Board::Board(){


}

Board::~Board(){}

void Board::populate(){

	srand(time(0));
	for(int r = 0; r <= BOARDSIZE; r++){
		for(int c = 0; c <= BOARDSIZE; c++){
			b[r][c] = rand()%20;
		}
	}

}

void Board::displayBoard(){

	for(int r = 0; r < BOARDSIZE; r++){
		for(int c = 0; c < BOARDSIZE; c++){
			cout << b[r][c] << " ";
		}
		cout << endl;
	}

}

void Board::findPath( iPair start, iPair end ){
	
	int distance[BOARDSIZE][BOARDSIZE] = {INT_MAX};
	set< iPair > visited; 

	/// @TODO: Remove
	/*
	set <pair <int, int> > s;
	s.insert(make_pair(1, 10));
	if (s.find(make_pair(1, 10)) != s.end()) cout << "FOUND!!!" << endl;
	if (s.find(make_pair(1, 5)) != s.end()) cout << "FOUND SECOND!!!" << endl;
	*/
	
	// start.first = column, start.second = row 
	distance[start.first][start.second] = 0;
	
	// keep track of smallest neightbors that alg will visit
	priority_queue< pPair, vector< pPair >, greater<pPair > > pq; 
	
	// put start location and weight in queue
	pq.push(make_pair(b[start.first][start.second], start));
	
	while(!pq.empty()){
		
		iPair location = pq.top().second;
		pq.pop();

		if (visited.find(location) != visited.end()) continue;
		visited.insert(location);
		
		
	}
	
}


void Board::displayPath(){}


