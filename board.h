/*
 * Patrick Bald
 * Board class method prototypes
 */

#include <vector>
#include <set>

using namespace std;

const int BOARDSIZE = 8;

class Board {
	public:
		Board();
		~Board();
		void populate();
		void findPath(int, int, int, int);
		void displayPath();
	private:
		int dijkBoard[BOARDSIZE][BOARDSIZE];
		int V = BOARDSIZE * BOARDSIZE;

};
