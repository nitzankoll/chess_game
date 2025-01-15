#include "Queen.h"
#include <iostream>
#include "Rook.h"


Queen::Queen(int src) : Bishop(src) {}


string Queen::type6(string board, string src, string dst)
{
	string str;
	int srcPlace;
	srcPlace = (src[0] - 'a' + 1) + (8 * (8 - atoi(&src[1]))) - 1;
	Rook rook(srcPlace);
	str = Bishop::type6(board, src, dst);// check if the move is possible for a bishop
	if (str == "6")
	{
		str = rook.type6(board, src, dst);// check if the move is possible for a rook
	}
	return str;
}