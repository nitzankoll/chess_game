#include "Piece.h"
#include <iostream>
#define FIRSTROW 8
#define FIRSTCOL 'a'


Piece::Piece(int src) : ValidType()
{
	_sourceIndex = src;
}


string Piece::move(string board, string src, string dst) // call after we checked if it's valid; 
{
	int source = 0;
	int destination = 0;
	source = (src[0] - 'a' + 1) + (8 * (8 - atoi(&src[1]))) - 1;// index in the board's string
	destination = (dst[0] - 'a' + 1) + (8 * (8 - atoi(&dst[1]))) - 1;// index in the board's string
	board[destination] = board[source];
	board[source] = '#';
	return board;
}

bool Piece::checkIfInMiddle(int * arr, int size, string src, string dst, string board)
{
	int i = 0;
	bool answer = 0;
	for (i = 0; i < size; i++)// check if there are not pieces between the src and the dst
	{
		if (board[arr[i]] != '#')
		{
			answer = 1;
		}
	}
	return answer;
}
void Piece::printkinds() {}
string Piece::changeKind(bool turn, string board, string dst) { return "0"; }