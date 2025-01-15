#pragma once
#include <string>
using std::string;

class ValidType
{
public:
	ValidType();
	void type2(int src, bool turn, string board); // check if in src there is a piece, and if the piece is yours (white or black) 
	void type3(string board, string dst, bool turn); // check  if in dst you have piece of yours (white or black)
	void type5(string dst, string src); // check if the src and dst are on the board
	virtual string type6(string board, string src, string dst); // virtual function to check if the piece move is legal
	void type7(string src, string dst); // check if src and dst are same
	string type8(string board, bool turn, string dst, string src); // check if you did a checkmate
	void checkIfValid(string board, string src, string dst, bool turn); // call to all the types and return what happend in the turn (which type to return), whether the move is valid
	string getType(); // return the type
	void changeType(string type); // change the type
	string type1(string board, bool turn, string dst, string src); // check if you made a chess
	string isValidForType1(string board, string src, string dst, bool turn); //check if the move is legal for type 1
	string type4(string board, bool turn, string dst, string src); // check if the move saves you from chess or if your move cause the opponent to make a chess on you

private:
	string _type; // the type ("0", "1" ,.... , "8")

};