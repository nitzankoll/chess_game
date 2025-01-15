#include "ValidType.h"
#include "Piece.h"
#include "Manager.h"
#include <iostream>

ValidType::ValidType()
{
	_type = "0";
}

void ValidType::changeType(string type)
{
	_type = type;
}

string ValidType::type1(string board, bool turn, string dst, string src)
{
	string str = "0";
	string kingPlace;
	Manager manage(board.c_str());
	Piece * piece = manage.whichPiece(src);
	manage.changeBoard(piece->move(board, src, dst));
	char c = 'a';
	char num = '1';
	char place[3] = { NULL };
	int len = 0;
	for (c = 'a'; c < 'i'; c++) //find the opponent's king's place
	{
		place[0] = c;
		for (num = '1'; num < '9'; num++)
		{
			place[1] = num;
			len = (place[0] - 'a' + 1) + (8 * (8 - atoi(&place[1]))) - 1;
			if ((manage.getBoard()[len] == 'k') && (turn == 0))
			{
				kingPlace = place;
			}
			else if ((manage.getBoard()[len] == 'K') && (turn == 1))
			{
				kingPlace = place;
			}
		}
	}
	c = 'a';
	num = '1';
	for (c = 'a'; c < 'i'; c++)// run over the places in the board
	{
		place[0] = c;
		for (num = '1'; num < '9'; num++)
		{
			place[1] = num;
			len = (place[0] - 'a' + 1) + (8 * (8 - atoi(&place[1]))) - 1;
			if ((manage.getBoard()[len] != '#') && ((isupper(manage.getBoard()[len]) && turn == 0) || (islower(manage.getBoard()[len]) && turn == 1)))
			{
				if (isValidForType1(manage.getBoard(), place, kingPlace, turn) == "0")//checks if at least one of my pieces can 'eat' the opponent's king
				{
					str = "1";
				}
			}
		}
	}
	delete piece;
	return str;
}

string ValidType::isValidForType1(string board, string src, string dst, bool turn)
{
	Manager manage(board.c_str());
	Piece * piece;
	ValidType valid;
	int source = 0;
	int dest = 0;
	string str = "5";
	valid.type5(dst, src);
	if (valid.getType() == "0") // check the relevant types ( ignore type 5 please, its just for make sure obvious thing)
	{
		source = (src[0] - 'a' + 1) + (8 * (8 - atoi(&src[1]))) - 1;
		piece = manage.whichPiece(src); // we have to create dynamic object to get into the relevant type6 (its virtual)
		piece->type2(source, turn, board);
		if (piece->getType() == "0")
		{
			piece->type7(src, dst);

			if (piece->getType() == "0")
			{
				if (piece->type6(board, src, dst) == "6")
				{
					piece->changeType("6");
				}
			}
		}
		str = piece->getType();
		delete piece;
	}
	return str;
}

void ValidType::type2(int src, bool turn, string board)
{
	if (turn == 0)
	{
		if (islower(board[src]))
		{
			changeType("2");
		}
	}
	else
	{
		if (isupper(board[src]))
		{
			changeType("2");
		}
	}
}

void ValidType::type3(string board, string dst, bool turn)
{
	int dest = 0;
	dest = (dst[0] - 'a' + 1) + (8 * (8 - atoi(&dst[1]))) - 1;
	if (turn == 0)
	{
		if (isupper(board[dest]))
		{
			changeType("3");
		}
	}
	else
	{
		if (islower(board[dest]))
		{
			changeType("3");
		}
	}
}

string ValidType::type4(string board, bool turn, string dst, string src)
{
	string str = "0";
	turn = !(turn);
	str = type1(board, turn, dst, src); // if the opponent make a chess on us
	if (str == "1")
	{
		str = "4";
	}
	return str;
}

void ValidType::type5(string dst, string src)
{
	if ((src[0] >= 'a') && (src[0] <= 'h') && (atoi(&src[1]) >= 1) && (atoi(&src[1]) <= 8) && (dst[0] >= 'a') && (dst[0] <= 'h') && (atoi(&dst[1]) >= 1) && (atoi(&dst[1]) <= 8))
	{
		changeType("0");
	}
	else
	{
		changeType("5");
	}
}

string ValidType::type6(string board, string src, string dst) { return "0"; }

void ValidType::type7(string src, string dst)
{
	if (src == dst)
	{
		changeType("7");
	}
}

string ValidType::type8(string board, bool turn, string dst, string src)
{
	turn = !(turn); // to check if the other player can save himself from my chess
	int source = 0;
	string str;
	string toReturn = "8";
	ValidType valid;
	Manager manage(board.c_str());
	Piece * piece = manage.whichPiece(src);
	manage.changeBoard(piece->move(board, src, dst));
	delete piece;
	char c = 'a';
	char num = '1';
	char ch = 'a';
	char number = '1';
	char srcPlace[3] = { NULL };
	char dstPlace[3] = { NULL };
	int len = 0;
	for (c = 'a'; c < 'i'; c++)
	{
		srcPlace[0] = c;
		for (num = '1'; num < '9'; num++) // run over all the indexes in the board for src
		{
			srcPlace[1] = num;
			source = (srcPlace[0] - 'a' + 1) + (8 * (8 - atoi(&srcPlace[1]))) - 1;
			if (((turn == 0) && isupper(manage.getBoard()[source])) || ((turn == 1) && islower(manage.getBoard()[source])))
				//if the piece belongs to the relevant player(actually, the opponent)
			{
				for (ch = 'a'; ch < 'i'; ch++)
				{
					dstPlace[0] = ch;
					for (number = '1'; number < '9'; number++)// run over all the indexes in the board for dst
					{
						dstPlace[1] = number;
						valid.changeType("0");
						valid.type7(srcPlace, dstPlace); // starts to check if the move is legal
						if (valid.getType() == "0")
						{
							valid.type3(manage.getBoard(), dstPlace, turn);
							if (valid.getType() == "0")
							{
								piece = manage.whichPiece(srcPlace);
								if (piece->type6(manage.getBoard(), srcPlace, dstPlace) == "0")
								{
									if (valid.type4(manage.getBoard(), turn, dstPlace, srcPlace) == "0") // checks if the opponent can save himself
									{
										delete piece;
										toReturn = "1";
										break;
									}
								}
								delete piece;
							}
						}
					}
					if (toReturn == "1") // to save time
					{
						break;
					}
				}
			}
			if (toReturn == "1") // to save time
			{
				break;
			}
		}
		if (toReturn == "1") // to save time
		{
			break;
		}
	}
	return toReturn;
}

void ValidType::checkIfValid(string board, string src, string dst, bool turn)
{
	int source = 0;
	type5(dst, src);
	if (getType() == "0") // check all the types (1 - 8), if no type matches, then _type will stay "0"
	{
		source = (src[0] - 'a' + 1) + (8 * (8 - atoi(&src[1]))) - 1;
		type2(source, turn, board);
		if (getType() == "0")
		{
			type3(board, dst, turn);
			if (getType() == "0")
			{
				if (type4(board, turn, dst, src) == "4")
				{
					changeType("4");
				}
				if (getType() == "0")
				{
					type7(src, dst);
					if (getType() == "0")
					{
						if (type6(board, src, dst) == "6")
						{
							changeType("6");
						}
						if (getType() == "0")
						{
							if (type1(board, turn, dst, src) == "1")
							{
								changeType("1");
							}
						}
					}
				}
			}
		}
	}
	if (getType() == "1") // if I made a chess, I check if its a checkmate ( if the opponent can't save himself) 
	{
		if (type8(board, turn, dst, src) == "8")
		{
			changeType("8");
		}
	}
}

string ValidType::getType()
{
	return _type;
}