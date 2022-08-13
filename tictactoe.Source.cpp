#include <iostream>
#include <string>
#include <cmath>
using namespace std;
char char1 = 'X'; //default characters
char char2 = 'Y';


char gameetable[3][3] = {
	{'1','2','3'},{'4','5','6'},{'7','8','9'}
}; // table


void write()
{
	for (int i = 0; i < 3; i++) {
		cout << " __|___|___" << endl;
		cout << "|";
		for (int a = 0; a < 3; a++) {
		
			cout << gameetable[i][a] << " | ";
		}cout << endl;

	}return;
} //writing table

int check () {
	if (gameetable[0][0] == gameetable[0][1] && gameetable[0][1] == gameetable[0][2])return 1;
	else if (gameetable[1][0] == gameetable[1][1] && gameetable[1][1] == gameetable[1][2])return 1;
	else if (gameetable[2][0] == gameetable[2][1] && gameetable[2][1] == gameetable[2][2])return 1;
	else if (gameetable[0][0] == gameetable[1][1] && gameetable[1][1] == gameetable[2][2])return 1;
	else if (gameetable[0][2] == gameetable[1][1] && gameetable[1][1] == gameetable[2][0])return 1;
	else if (gameetable[0][0] == gameetable[1][0] && gameetable[1][0] == gameetable[2][0])return 1;
	else if (gameetable[0][1] == gameetable[1][1] && gameetable[1][1] == gameetable[2][1])return 1;
	else if (gameetable[0][2] == gameetable[1][2] && gameetable[1][2] == gameetable[2][2])return 1;
	else return 0;
}

void askplayer()
{
	cout << "char1?" << endl;
	cin >> char1;
	cout << "char2?" << endl;
	cin >> char2;
}

void mainplayer() {
	char cina;
	cout << "Player 1 which one you would like to chnage? write numb: ";
	cin >> cina;

	int truefalse; // to check if there is any matches in game

	for (int i = 0; i < 3; i++) {
		for (int a = 0; a < 3; a++) {

			if (gameetable[i][a] == cina) {

				gameetable[i][a] = char1;
			}
		}

		truefalse = check();
	
	
	}

	if (truefalse == 1) { cout << "player 1 won " << endl; return; }
	
	cout << "Player 2 which one you would like to chnage? write numb: ";

	cin >> cina; //again same things

	for (int i = 0; i < 3; i++) {
		for (int a = 0; a < 3; a++) {

			if (gameetable[i][a] == cina) {

				gameetable[i][a] = char2;
			}
		}

		truefalse = check();
	}

	if (truefalse == 1) { cout << "player 2 won " << endl; return; }

	return;
}


int main(){

	cout << "Welcome" << endl;
	askplayer(); 
	
	int checkqueue = 0; // almost 5 writing could be reached in 9x9 table,we will follow this in the do while 

	do {
		write();
		mainplayer();
		checkqueue++;
		if (check() == 1) {break;}
	} while (checkqueue!=5);

	if (check() != 1) { cout << "no player won" << endl; }
	cout << "Thanks for playing" << endl;
}




