#include "Knight.h"
#include <iostream>

Knight::Knight(int src) : Piece(src) {}

string Knight::type6(string board, string src, string dst)
{
	string str = "6"; // if the move is illegal, str will stay "6", else it will be "0"
	if ((dst[0] - src[0] == 2) || (dst[0] - src[0] == -2))
	{
		if ((atoi(&dst[1]) - atoi(&src[1]) == 1) || (atoi(&dst[1]) - atoi(&src[1]) == -1))
		{
			str = "0";
		}
	}
	else if ((dst[0] - src[0] == 1) || (dst[0] - src[0] == -1))
	{
		if ((atoi(&dst[1]) - atoi(&src[1]) == 2) || (atoi(&dst[1]) - atoi(&src[1]) == -2))
		{
			str = "0";
		}
	}
	return str;
}