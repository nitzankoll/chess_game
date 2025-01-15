#pragma once
#include <string>
using std::string;
#include "Piece.h"

class Manager
{
public:
	Manager(string board); //constructor
	string getBoard(); // return the board
	string getSrc(); // return the src of the move
	string getDst(); // return the dst of the move
	int getTurn(); // return the turn 0 to white and 1 to black
	void changeTurn(); // change turn 
	void printBoard(); // print the board
	void changeBoard(string newBoard);  // change the board to the new board after move
	void separate(string msgFromGraphics); // separate the msg from the Graphics to src and dst (e2d5 - src=e2 , dst=d5)
	bool checkIfEmpty(string src); // return if in the src you have a piece 
	Piece* whichPiece(string src); // return piece according to the letter


private:
	string _board; // the board
	string _src; // the src
	string _dst; // the dst
	bool _turn; // the turns
};