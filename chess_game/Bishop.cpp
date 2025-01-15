#include "Bishop.h"
#include <iostream>

Bishop::Bishop(int src) : Piece(src) {}

string Bishop::type6(string board, string src, string dst)
{
	int i = 0;
	string str = "0";
	int len = 0;
	bool inMiddle = 0;
	int biggerNumber;
	int smallNumber = 0;
	char biggerChar;
	char smallChar;
	char place[3] = { NULL };
	int placeNum;
	int * arr;
	int charDifference;
	int numDifference;
	charDifference = dst[0] - src[0];
	numDifference = dst[1] - src[1];
	if ((charDifference != numDifference) && (charDifference != 0 - numDifference))
	{
		str = "6";
	}
	else
	{
		arr = new int[6]; // max len(between two indexes) for bishop ( diagonal )
		if (charDifference > 0 && numDifference > 0)
		{
			smallChar = src[0];
			biggerChar = dst[0];
			smallNumber = atoi(&src[1]);
			biggerNumber = atoi(&dst[1]);
		}
		else if (charDifference < 0 && numDifference < 0)
		{
			smallChar = dst[0];
			biggerChar = src[0];
			smallNumber = atoi(&dst[1]);
			biggerNumber = atoi(&src[1]);
		}
		else if (charDifference > 0 && numDifference < 0)
		{
			smallChar = src[0];
			biggerChar = dst[0];
			smallNumber = atoi(&dst[1]);
			biggerNumber = atoi(&src[1]);
		}
		else if (charDifference < 0 && numDifference > 0)
		{
			smallChar = dst[0];
			biggerChar = src[0];
			smallNumber = atoi(&src[1]);
			biggerNumber = atoi(&dst[1]);
		}

		if (smallNumber != 0)
		{
			if (charDifference == numDifference)
			{
				smallNumber++;
				for (smallNumber; smallNumber < biggerNumber; smallNumber++)// run over the places between the src and dst in the move
				{
					smallChar++;
					place[0] = smallChar; // same as dest[0]
					place[1] = smallNumber + 48; // for ascii
					placeNum = (place[0] - 'a' + 1) + (8 * (8 - atoi(&place[1]))) - 1;
					arr[len] = placeNum;
					len++;
				}
			}
			else
			{
				biggerNumber--;
				for (biggerNumber; biggerNumber > smallNumber; biggerNumber--)// run over the places between the src and dst in the move
				{
					smallChar++;
					place[0] = smallChar; // same as dest[0]
					place[1] = biggerNumber + 48; // for ascii
					placeNum = (place[0] - 'a' + 1) + (8 * (8 - atoi(&place[1]))) - 1;
					arr[len] = placeNum;
					len++;
				}
			}
		}
		if (len != 0)// there src and the dst are not nearby
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
