#include <iostream>
#include "move.h"

int main() {
	Move move1(1.1, 2.2);
	Move move2(2.2, 3.3);
	Move move3;

	move3 = move1.add(move2);
	move3.showmove();
	move3.reset(5.5, 6.6);
	move3.showmove();
	return 0;
}