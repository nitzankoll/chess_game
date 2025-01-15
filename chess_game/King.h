#pragma once
#include <string>
#include "Piece.h"
using std::string;

class King : public Piece
{
public:
	King(int src); //constructor
	string type6(string board, string src, string dst); // check if the move is possible
};