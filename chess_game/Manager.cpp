#include "Manager.h"
#include "Piece.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include <iostream>

Manager::Manager(string board)
{
	_board = board;
	_turn = 0; // white starts
}

int Manager::getTurn()
{
	return _turn;
}

void Manager::changeTurn()
{
	if (_turn == 0)
	{
		_turn = 1;
	}
	else
	{
		_turn = 0;
	}
}

string Manager::getBoard()
{
	return _board;
}

string Manager::getSrc()
{
	return _src;
}

string Manager::getDst()
{
	return _dst;
}

void Manager::printBoard()
{
	int i = 0;
	int j = 0;
	int z = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			std::cout << _board[z];
			z++;
		}
		std::cout << std::endl;
	}
}

void Manager::changeBoard(string newBoard)
{
	_board = newBoard;
}

void Manager::separate(string msg)
{
	char src[3] = { NULL };
	char dst[3] = { NULL };
	src[0] = msg[0];
	src[1] = msg[1];
	dst[0] = msg[2];
	dst[1] = msg[3];
	_src = src;
	_dst = dst;
}

bool Manager::checkIfEmpty(string src)// check if there is '#' in the src
{
	bool answer = 0;
	int sourceIndex = 0;
	sourceIndex = (src[0] - 'a' + 1) + (8 * (8 - atoi(&src[1]))) - 1;
	if (_board[sourceIndex] == '#')
	{
		answer = 1;
	}
	return answer;
}

Piece* Manager::whichPiece(string src)
{
	Piece * piece;
	int sourceIndex = 0;
	sourceIndex = (src[0] - 'a' + 1) + (8 * (8 - atoi(&src[1]))) - 1;
	switch (tolower(_board[sourceIndex])) // checks which kind of piece is in the src, and uses polymorphism
	{
	case ('k'):
		piece = new King(sourceIndex);
		break;
	case ('n'):
		piece = new Knight(sourceIndex);
		break;
	case ('b'):
		piece = new Bishop(sourceIndex);
		break;
	case ('p'):
		piece = new Pawn(sourceIndex);
		break;
	case ('q'):
		piece = new Queen(sourceIndex);
		break;
	case ('r'):
		piece = new Rook(sourceIndex);
		break;
	default:
		piece = new Rook(sourceIndex);
		throw("Empty piece arrived into the function: whichPiece");

	}
	return piece;
}