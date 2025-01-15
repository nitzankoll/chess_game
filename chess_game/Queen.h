#pragma once
#include <string>
#include "Bishop.h"
#include "Rook.h"
using std::string;

class Queen : public Bishop
{
public:
	Queen(int src); //constructor
	string type6(string board, string src, string dst); // check if the move is possible
};