#include "Rook.h"
#include <iostream>
#include "ValidType.h"
using std::string;


Rook::Rook(int src) : Piece(src) {}


string Rook::type6(string board, string src, string dst)
{
	int i = 0;
	string str = "0";
	int len = 0;
	bool inMiddle = 0;
	int biggerNumber;
	int smallNumber;
	char biggerChar;
	char smallChar;
	char place[3] = { NULL };
	int placeNum;
	int * arr;
	if ((src[0] != dst[0]) && (src[1] != dst[1]))
	{
		str = "6";
	}
	else
	{
		arr = new int[6]; // max len(between two indexes) for rook
		if (src[0] == dst[0])
		{
			if (atoi(&src[1]) > atoi(&dst[1]))
			{
				biggerNumber = atoi(&src[1]);
				smallNumber = atoi(&dst[1]);
			}
			else
			{
				biggerNumber = atoi(&dst[1]);
				smallNumber = atoi(&src[1]);
			}
			smallNumber++;
			for (smallNumber; smallNumber < biggerNumber; smallNumber++)// run over the places between the src and dst in the move
			{
				place[0] = src[0]; // same as dest[0]
				place[1] = smallNumber + 48; // for ascii
				placeNum = (place[0] - 'a' + 1) + (8 * (8 - atoi(&place[1]))) - 1;
				arr[len] = placeNum;
				len++;
			}
		}
		else
		{
			if ((int)src[0] > (int)dst[0])
			{
				biggerChar = src[0];
				smallChar = dst[0];
			}
			else
			{
				smallChar = src[0];
				biggerChar = dst[0];
			}
			smallChar++;
			for (smallChar; smallChar < biggerChar; smallChar++)// run over the places between the src and dst in the move
			{
				place[1] = src[1]; // same as dest[1]
				place[0] = smallChar; // for ascii
				placeNum = (place[0] - 'a' + 1) + (8 * (8 - atoi(&place[1]))) - 1;
				arr[len] = placeNum;
				len++;
			}
		}
		if (len != 0) // the src and the dst are not nearby 
		{
			inMiddle = checkIfInMiddle(arr, len, src, dst, board);
			if (inMiddle == 1)
			{
				str = "6";
			}
		}
		delete[] arr;
	}
	return str;
}