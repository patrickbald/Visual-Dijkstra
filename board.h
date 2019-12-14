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
const int wd = 800;
const int ht = 800;
const int l = 48;
const int startC = 220;
const int startR = 220;
const int offset = 48/2;

class Board {
	public:
		Board();
		~Board();
		void populate();
		int findPath( pair<int, int>, pair<int, int> ); // map < iPair, iPair >
		void displayBoard();
		void displayPath();
		set < iPair > getNeighbors( iPair );
		void initDistance();
		void addToPath(iPair, iPair);
		map <iPair, iPair> getPath();
	private:
		int b[BOARDSIZE][BOARDSIZE];
		int distance[BOARDSIZE][BOARDSIZE];
		map < iPair, iPair > path;
};
