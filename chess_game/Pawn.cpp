#include "Pawn.h"
#include <iostream>

Pawn::Pawn(int src) : Piece(src) {}

string Pawn::type6(string board, string src, string dst)
{
	string str = "6";
	char charType;
	int place;
	int arr[1] = { 0 };
	char stringPlace[3] = { NULL };
	charType = board[_sourceIndex];
	if (charType == 'P')
	{
		if (atoi(&dst[1]) - atoi(&src[1]) == 1)  //eat or walk
		{
			place = (dst[0] - 'a' + 1) + (8 * (8 - atoi(&dst[1]))) - 1;
			if (dst[0] == src[0])
			{
				if (board[place] == '#')
				{
					str = "0";
				}
			}
			else if ((dst[0] - src[0] == 1) || (dst[0] - src[0] == -1))
			{
				if (board[place] != '#') // we already know that its not our piece. the dst isn't empty
				{
					str = "0";
				}
			}
		}
		else if ((atoi(&dst[1]) - atoi(&src[1]) == 2) && (dst[0] == src[0]))// only at the first move of each pawn
		{
			if (atoi(&src[1]) == 2) // it means that the pawn didn't move yet
			{
				stringPlace[0] = src[0];
				stringPlace[1] = src[1] + 1;
				place = (stringPlace[0] - 'a' + 1) + (8 * (8 - atoi(&stringPlace[1]))) - 1;
				arr[0] = place;
				place -= 8;
				if (board[place] == '#')
				{
					if (checkIfInMiddle(arr, 1, src, dst, board) == 0)//checks if the move can be made
					{
						str = "0";
					}
				}
			}
		}
	}
	else
	{
		if (atoi(&dst[1]) - atoi(&src[1]) == -1)  //eat or walk
		{
			place = (dst[0] - 'a' + 1) + (8 * (8 - atoi(&dst[1]))) - 1;
			if (dst[0] == src[0])
			{
				if (board[place] == '#')
				{
					str = "0";
				}
			}
			else if ((dst[0] - src[0] == 1) || (dst[0] - src[0] == -1))
			{
				if (board[place] != '#' ) // we already know that its not our piece
				{
					str = "0";
				}
			}
		}
		else if ((atoi(&dst[1]) - atoi(&src[1]) == -2) && (dst[0] == src[0]))// only at the first move of each pawn
		{
			if (atoi(&src[1]) == 7) // it means that the pawn didn't move yet
			{
				stringPlace[0] = src[0];
				stringPlace[1] = src[1] - 1;
				place = (stringPlace[0] - 'a' + 1) + (8 * (8 - atoi(&stringPlace[1]))) - 1;
				arr[0] = place;
				place += 8;
				if (board[place] == '#')
				{
					if (checkIfInMiddle(arr, 1, src, dst, board) == 0) //checks if the move can be made
					{
						str = "0";
					}
				}
			}
		}
	}
	return str;
}
void Pawn::printkinds()
{
	std::cout << "b to bishop" << std::endl;
	std::cout << "n to knight" << std::endl;
	std::cout << "q to queen" << std::endl;
	std::cout << "r to rook" << std::endl;
	std::cout << "p to pawn" << std::endl;
}
string Pawn::changeKind(bool turn, string board, string dst)
{
	string kind = "a";
	while (kind != "n" && kind != "q" && kind != "r" && kind != "b" && kind != "p")
	{
		printkinds();
		std::cin >> kind;
	}
	switch (kind[0])
	{
	case 'b':
		if (turn)
		{
			board[(dst[0] - 'a' + 1) + (8 * (8 - atoi(&dst[1]))) - 1] = 'b';
		}
		else
		{
			board[(dst[0] - 'a' + 1) + (8 * (8 - atoi(&dst[1]))) - 1] = 'B';
		}
		break;
	case 'n':
		if (turn)
		{
			board[(dst[0] - 'a' + 1) + (8 * (8 - atoi(&dst[1]))) - 1] = 'n';
		}
		else
		{
			board[(dst[0] - 'a' + 1) + (8 * (8 - atoi(&dst[1]))) - 1] = 'N';
		}
		break;
	case 'q':
		if (turn)
		{
			board[(dst[0] - 'a' + 1) + (8 * (8 - atoi(&dst[1]))) - 1] = 'q';
		}
		else
		{
			board[(dst[0] - 'a' + 1) + (8 * (8 - atoi(&dst[1]))) - 1] = 'Q';
		}
		break;
	case 'r':
		if (turn)
		{
			board[(dst[0] - 'a' + 1) + (8 * (8 - atoi(&dst[1]))) - 1] = 'r';
		}
		else
		{
			board[(dst[0] - 'a' + 1) + (8 * (8 - atoi(&dst[1]))) - 1] = 'R';
		}
		break;
	case 'p':
		break;
	}
	return board;
}