/*





X Game is a game that runs in the windows cmd console. 
The game has a simple menu: an option to play, and an option to quit.
The game displays 1-3 'X' characters on the screen.  
The user must press the correct corresponding number key on their keyboard.
If 'X' is displayed, the user must press '1'.
If 'X X' is displayed, the user must press '2'.
if 'X X X' is displayed, the user must press '3'.
The game ends if the user presses an incorrect key.
The game ends if the user fails to press the correct in a the given amount of time.
The game displays your score at the end of the game.

The C++ code for the game is below.







*/
#include <iostream>
#include <ctime> //TIME
#include <cctype> //toupper
#include <cstring> //strlen
#include <conio.h> //for _getche
#include <Windows.h> //for SetConsoleTextAttribute
using namespace std;

void game();
void displayMenu();
bool process();
void centerstring(char s[]);

int main()
{
	bool play;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 10);

	do
	{
	displayMenu();
	play = process();
	}
	while(play);

	return 0;
}

void game()
{
	int randomNum = 0, 
		input = -1, 
		score = -1,
		countdown = 0,
		TIME;
	char xString[10];
	bool timeup = false;
	
	do
	{
		srand((int)time(0) - rand() % 7);
		randomNum = (rand() % 3) + 1;

		int i = 0;
		for(; i < randomNum * 2; i+=2)
		{
			xString[i] = 'X';
			xString[i+1] = ' ';
		}
		xString[i] = '\0';
		cout << "\n\n\n\n\n"; 
		centerstring(xString);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

		TIME = (int)time(0);
		input = _getche();
		cout << "\a";
		if(((int)time(0) - TIME) > 1)
			timeup = true;

		score++;
	}
	while((!timeup) && (input == randomNum + 48));

	cout << "\n\n\n\n\n";
	if(timeup)
		centerstring("  TOO SLOW.\n");
	else
		centerstring("   WRONG NUMBER. \n");
	centerstring("  GAME OVER\n");
	centerstring("SCORE: ");
	cout << score << endl << endl;
	
}

void displayMenu()
{
	cout << "\n\n\n\n\n";
	centerstring(" Press ANY key to PLAY\n");
	centerstring(" Press Q to QUIT\n");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

bool process()
{
	char input;
	bool play = true;

	input = _getche();
	if(toupper(input) == 'Q')
		play = false;
	
	if(play)
		game();

	return play;
}

void centerstring(char s[])
{
	int l = strlen(s);
	int pos = (100-l)/2;

	for(int i = 0; i < pos; i++)
		cout<<" ";

	cout << s;
}
