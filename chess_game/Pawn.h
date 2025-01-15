#pragma once
#include <string>
#include "Piece.h"
using std::string;

class Pawn : public Piece
{
public:
	Pawn(int src); //constructor
	string type6(string board, string src, string dst); // check if the move is possible
	void printkinds(); // print the piece you can switch 
	string changeKind(bool turn, string board, string dst); //change the pawn to other piece
};