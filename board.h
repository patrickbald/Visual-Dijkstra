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
		populate();
		findPath(int, int, int, int);
		displayPath();
	private:
		int dijkBoard[BOARDSIZE][BOARDSIZE];

}
