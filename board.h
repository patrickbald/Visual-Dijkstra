/*
 * Patrick Bald
 * Board class method prototypes
 */

#include <vector>
#include <set>

using namespace std;

const int BOARDSIZE = 8;
typedef pair<int, int> iPair;
typedef pair< int, pair<int, int> > pPair;

class Board {
	public:
		Board();
		~Board();
		void populate();
		void findPath( pair<int, int>, pair<int, int> );
		void displayBoard();
		void displayPath();
	private:
		int b[BOARDSIZE][BOARDSIZE];

};
