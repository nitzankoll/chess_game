#pragma once
#include <string>
#include "Piece.h"
using namespace std;
class Bishop : public Piece
{
public:
	Bishop(int src); //constructor
	string type6(string board, string src, string dst); // check if the move is possible

};
