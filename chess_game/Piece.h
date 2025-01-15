#pragma once
#include <string>
#include "ValidType.h"
using std::string;

class Piece : public ValidType
{
public:
	Piece(int src);
	string move(string board, string src, string dst); // move the piece in the board
	bool checkIfInMiddle(int * arr, int size, string src, string dst, string board); // check if there are pieces in the middle of the movement
	virtual void printkinds(); // print the pieces that you can switch if you arrived with a pawn to the last line
	virtual string changeKind(bool turn, string board, string dst); // change the pawn to other piece
protected:
	int _sourceIndex; // index in board string

};