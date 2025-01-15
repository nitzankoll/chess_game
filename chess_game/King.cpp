#include "King.h"
#include <iostream>

King::King(int src) : Piece(src) {}
string King::type6(string board, string src, string dst)
{
	string str = "0";
	if (!(((dst[0] - src[0] == 0) || (dst[0] - src[0] == 1) || (dst[0] - src[0] == -1)) && ((atoi(&dst[1]) - atoi(&src[1]) == 0) || (atoi(&dst[1]) - atoi(&src[1]) == 1) || (atoi(&dst[1]) - atoi(&src[1]) == -1))))
	//check if the src and the dst are nearby
	{
		str = "6";
	}
	return str;
}

