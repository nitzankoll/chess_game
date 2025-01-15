#pragma once
#include <string>
#include "Piece.h"
using std::string;

class Knight : public Piece
{
public:
	Knight(int src); //constructor
	string type6(string board, string src, string dst); // check if the move is possible
};