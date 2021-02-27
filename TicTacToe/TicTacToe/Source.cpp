#include <iostream>
#include <random>

using namespace std;


void printResult(int _result)
{
	switch (_result) {
	case 1:
		cout << "Player 1 wins the board!" << endl;
		break;
	case 2:
		cout << "Player 2 wins the board!" << endl;
		break;
	case 3:
		cout << "DRAW! No more moves" << endl;
		break;
	case -1:
		cout << "Board Corruption Detected" << endl;
		break;
	default:
		cout << "No Winner Found." << endl;
	}
	cout << endl;

}
//Will return the first winner it finds on the board
int checkForWin(int _board[3][3])
{
	int tokenCount = 0;
	bool playerOneWins = false, playerTwoWins = false;
	for each (int var in _board)
	{
		if (!(var == 0 || var == 1 || var == 2))
			return -1;

		if (var != 0)
			tokenCount++;
	}

	if (tokenCount < 3)
		//not enough tokens for a win to be possible
		return 0;
	else
	{
		//Searching at top-left, middle-middle, and bottom-right
		if (_board[0][0] != 0) 
		{
			int currentToken = _board[0][0];
			//top row, left column and top left diagonal are possible
			if ((_board[0][0] == currentToken && _board[0][1] == currentToken && _board[0][2] == currentToken) ||
				(_board[0][0] == currentToken && _board[1][0] == currentToken && _board[2][0] == currentToken) ||
				(_board[0][0] == currentToken && _board[1][1] == currentToken && _board[2][2] == currentToken))
				//win found
				return currentToken;
		}
		if (_board[1][1] != 0)
		{
			int currentToken = _board[1][1];
			//middle row, middle column are possible
			if ((_board[1][0] == currentToken && _board[1][1] == currentToken && _board[1][2] == currentToken) ||
				(_board[0][1] == currentToken && _board[1][1] == currentToken && _board[2][1] == currentToken))
				//win found
				return currentToken;
		}
		if (_board[2][2] != 0)
		{
			int currentToken = _board[2][2];
			//bottom row, right column are possible
			if ((_board[2][0] == currentToken && _board[2][1] == currentToken && _board[2][2] == currentToken) ||
				(_board[0][2] == currentToken && _board[1][2] == currentToken && _board[2][2] == currentToken))
				//win found
				return currentToken;
		}
		if (_board[0][2] != 0)
		{
			int currentToken = _board[0][2];
			//top right diagonal is possible
			if (_board[2][0] == currentToken && _board[1][1] == currentToken && _board[0][2] == currentToken)
				//win found
				return currentToken;
		}

		//No winner was found
		if (tokenCount == 9)
			return 3;
		else
			return 0;
	}
}
void printBoard(int _board[3][3])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			cout << "|" << _board[i][j] << "|";
		}
		cout << endl;
	}
}

void main()
{
	//Player 1 token: 1
	//Player 2 token: 2
	int board[3][3];

	//Test 1 : Empty
	cout << "//Test 1 : Empty" << endl;
	board[0][0] = 0; board[0][1] = 0; board[0][2] = 0;
	board[1][0] = 0; board[1][1] = 0; board[1][2] = 0;
	board[2][0] = 0; board[2][1] = 0; board[2][2] = 0;

	printBoard(board);
	printResult(checkForWin(board));

	//Test 2 : Draw
	cout << "//Test 2 : Draw" << endl;
	board[0][0] = 1; board[0][1] = 2; board[0][2] = 1;
	board[1][0] = 2; board[1][1] = 1; board[1][2] = 1;
	board[2][0] = 2; board[2][1] = 1; board[2][2] = 2;

	printBoard(board);
	printResult(checkForWin(board));

	//Test 3 : Player 1 Wins
	cout << "//Test 3 : Player 1 Wins" << endl;
	board[0][0] = 1; board[0][1] = 2; board[0][2] = 1;
	board[1][0] = 1; board[1][1] = 1; board[1][2] = 1;
	board[2][0] = 2; board[2][1] = 1; board[2][2] = 2;

	printBoard(board);
	printResult(checkForWin(board));

	//Test 4 : Player 2 Wins
	cout << "//Test 4 : Player 2 Wins" << endl;
	board[0][0] = 2; board[0][1] = 2; board[0][2] = 1;
	board[1][0] = 1; board[1][1] = 2; board[1][2] = 1;
	board[2][0] = 2; board[2][1] = 1; board[2][2] = 2;

	printBoard(board);
	printResult(checkForWin(board));

	//Test 5 : 2 Winning Solutions, the first found is returned
	cout << "//Test 5 : 2 Winning Solutions, the first found is returned" << endl;
	board[0][0] = 2; board[0][1] = 2; board[0][2] = 2;
	board[1][0] = 1; board[1][1] = 2; board[1][2] = 1;
	board[2][0] = 1; board[2][1] = 1; board[2][2] = 1;

	printBoard(board);
	printResult(checkForWin(board));

	//Test 6 : 2 Winning Solutions, reversed, the first found is returned
	cout << "//Test 6 : 2 Winning Solutions, reversed, the first found is returned" << endl;
	board[0][0] = 1; board[0][1] = 1; board[0][2] = 1;
	board[1][0] = 1; board[1][1] = 2; board[1][2] = 1;
	board[2][0] = 2; board[2][1] = 2; board[2][2] = 2;

	printBoard(board);
	printResult(checkForWin(board));

	//Test 7 : Garbage Found
	cout << "//Test 7 : Garbage Found" << endl;
	board[0][0] = 1; board[0][1] = 2; board[0][2] = 8;
	board[1][0] = 5; board[1][1] = 7; board[1][2] = 9;
	board[2][0] = 6; board[2][1] = 1; board[2][2] = 42;

	printBoard(board);
	printResult(checkForWin(board));

	//Test 8 : Random Input
	cout << "//Test 8 : Random Input" << endl;
	int cont = 1;
	while (cont == 1)
	{
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				board[i][j] = rand() % 3;
			}
		}

		printBoard(board);
		printResult(checkForWin(board));

		cout << "Enter '1' to run another test" << endl;
		cin >> cont;
	}

	system("PAUSE");
}