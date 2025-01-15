#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Manager.h"
#include "Piece.h"
#include <exception>
#include <windows.h>
#include <Mmsystem.h>

#pragma comment(lib, "Winmm.lib")

using namespace std;
void main()
{
	string type;
	Piece* piece;
	Manager manage("rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR");// intiate the board
	srand(time_t(NULL));
	string str = "";
	int source;
	string toQuit = "0";
	string quit = "";
	mciSendString("open \"queen.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	while (toQuit!="8" && quit != "quit")
	{
		HINSTANCE result = ShellExecute(NULL, "open", "chessGraphics.exe", NULL, NULL, SW_SHOW);

		if ((INT_PTR)result <= 32) {
			std::cerr << "Failed to open the file. Error code: " << (INT_PTR)result << std::endl;
		}

		Sleep(1000); // waits until the file is opened
		Pipe p;
		bool isConnect = p.connect();

		string ans;

		while (!isConnect)
		{
			cout << "cant connect to graphics" << endl;
			cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
			cin >> ans;

			if (ans == "0")
			{
				cout << "trying connect again.." << endl;
				Sleep(5000);
				isConnect = p.connect();
			}
			else
			{
				p.close();
				return;
			}
		}


		char msgToGraphics[1024];
		// msgToGraphics should contain the board string accord the protocol
		str = manage.getBoard() + (std::to_string(manage.getTurn()));
		std::cout << str << std::endl;
		strcpy_s(msgToGraphics, str.c_str()); 

		p.sendMessageToGraphics(msgToGraphics);   // send the board string

												  // get message from graphics
		string msgFromGraphics = p.getMessageFromGraphics();
		while (msgFromGraphics != "quit")
		{
			// should handle the string the sent from graphics
			// according the protocol. Ex: e2e4           (move e2 to e4)

			manage.separate(msgFromGraphics);
			if (manage.checkIfEmpty(manage.getSrc()) == 0) // there is a piece
			{
				try
				{
					piece = manage.whichPiece(manage.getSrc()); // the 'throw' is inside this function, but it can't happen, its just for the syntax
					piece->checkIfValid(manage.getBoard(), manage.getSrc(), manage.getDst(), manage.getTurn());// checks if the move is valid include checks for chess and checkmate
					toQuit = piece->getType(); // if there is a checkmate, the loop will be stopped
					if ((piece->getType() == "0") || (piece->getType() == "1")) // the move is legal
					{
						manage.changeBoard(piece->move(manage.getBoard(), manage.getSrc(), manage.getDst())); // our board is changed because of the move
						source = (manage.getDst()[0] - 'a' + 1) + (8 * (8 - atoi(&manage.getDst()[1]))) - 1; // the index of the new src in the _board member in manage
						if (toupper(manage.getBoard()[source]) == 'P') // if it's a pawn
						{
							if (atoi(&manage.getDst()[1]) == 8 || atoi(&manage.getDst()[1]) == 1) // if it arrive to the end of the board
							{
								std::cout << "What kind of piece do you want?" << std::endl;
								manage.changeBoard(piece->changeKind(manage.getTurn(), manage.getBoard(), manage.getDst())); // chande the pawn to other piece that the user chooses
								manage.changeTurn();// if there was a move, the game keep running and now its the opponent turn
								delete piece;
								break;
							}
						}
						manage.changeTurn();
					}
					strcpy_s(msgToGraphics, (piece->getType()).c_str()); // msgToGraphics should contain the result of the operation
					delete piece;
				}
				catch (exception& e) // shouldn't happen. never happen 
				{
					cout << e.what() << endl;
				}
			}
			else
			{
				type = "2";
				strcpy_s(msgToGraphics, type.c_str());
			}

			manage.printBoard(); //only for us
			// return result to graphics	
			if (toQuit == "8")
			{
				mciSendString("play queen.mp3", NULL, 0, NULL);
			}
			p.sendMessageToGraphics(msgToGraphics);
			// get message from graphics
			msgFromGraphics = p.getMessageFromGraphics();
			quit = msgFromGraphics; //get the msgFromGraphics. if its "quit", the loop will be ended
		}
		p.close();
		Sleep(1000);
	}
	system("pause");
}