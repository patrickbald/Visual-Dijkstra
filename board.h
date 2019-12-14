/*
 * Patrick Bald
 * Board class method prototypes
 */

#include <vector>
#include <set>
#include <utility>
#include <climits>
#include <map>

using namespace std;

const int BOARDSIZE = 8;
typedef pair<int, int> iPair;
typedef pair< int, pair<int, int> > pPair;

class Board {
	public:
		Board();
		~Board();
		void populate();
		map< iPair, iPair > findPath( pair<int, int>, pair<int, int> );
		void displayBoard();
		void displayPath();
		set < iPair > getNeighbors( iPair );
		void initDistance();
	private:
		int b[BOARDSIZE][BOARDSIZE];
		int distance[BOARDSIZE][BOARDSIZE];
};
