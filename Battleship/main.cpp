#include <iostream>
#include <string>
#include <random>

using namespace std;

int generateRandomNumber(int maxValue);
void createBoard(char board[][26], char userBoard[][26]);
void generateBoats(char board[][26], int x[], int y[]);


int main()
{
	const int max = 5;
	int x[max];
	int y[max];
	char board[26][26] = { '~' };
	char userBoard[26][26] = { '~' };
	srand(time(NULL));

	for (int i = 0; i < max; i++)
	{
		x[i] = generateRandomNumber(25);
		y[i] = generateRandomNumber(25);
	}

	generateBoats(board, x, y);

	createBoard(board, userBoard);

	return 0;
}

int generateRandomNumber(int maxValue)
{
	int randomNum = rand() % maxValue + 1;
	return randomNum;
}

void createBoard(char board[][26], char userBoard[][26])
{
	for (int row = 1; row < 26; row++)
		for (int col = 1; col < 26; col++)
		{
			userBoard[row][col] = board[row][col];
			//userBoard[row][col] = '~';
			cout << userBoard[row][col];
			cout << "  ";
			if (col == 25)
				cout << endl;
		}
}

void generateBoats(char board[][26], int x[], int y[])
{
	int maxValue = 2;
	int vh[5];

	//CARRIER - #####

	//BATTLESHIP - ####

	//DESTROYER - ###
	vh[2] = generateRandomNumber(maxValue);
	if (vh[2] == 2) //Then the boat will be vertical
	{
		if (y[2] == 25 || y[2] == 24)
			y[2] = 23;

		for (int i = 0; i < 3; i++)
			board[x[2]][y[2] + i] = '#';

	}
	else //The boat will be horizontal
	{
		if (x[2] == 25 || x[2] == 24)
			x[2] = 23;

		for (int i = 0; i < 3; i++)
			board[x[2] + i][y[2]] = '#';
	}

	//SUB - ###
	vh[3] = generateRandomNumber(maxValue);
	if (vh[3] == 2) //Then the boat will be vertical
	{
		if (y[3] == 25 || y[3] == 24)
			y[3] = 23;

		for (int i = 0; i < 3; i++)
			board[x[3]][y[3] + i] = '#';

	}
	else //The boat will be horizontal
	{
		if (x[3] == 25 || x[3] == 24)
			x[3] = 23;

		for (int i = 0; i < 3; i++)
			board[x[3] + i][y[3]] = '#';
	}

	//PATROL BOAT - ##
	vh[4] = generateRandomNumber(maxValue);
	if (vh[4] == 2) //Then the boat will be vertical
	{
		if (y[4] == 25)
			y[4] = 24;

		board[x[4]][y[4]] = '#';
		board[x[4]][y[4] + 1] = '#';
	}
	else //The boat will be horizontal
	{
		if (x[4] == 25)
			x[4] = 24;

		board[x[4]][y[4]] = '#';
		board[x[4] + 1][y[4]] = '#';
	}

	for (int row = 1; row < 26; row++)
		for (int col = 1; col < 26; col++)
			if (board[row][col] == '#')
				board[row][col] = '#';
			else
				board[row][col] = '~';
}