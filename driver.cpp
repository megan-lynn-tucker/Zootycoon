/*********************************************************************
* Namme: driver.cpp
* Author: Megan Lynn Tuker
* Date: 02/16/2020
* Description:
* Input: If the player wishes to continue playing or not 
* Output: Gameplay and options for exiting before game over
* *********************************************************************/
#include<iostream>
#include<cstdlib>
#include"zoo.h"
#include"sea_lion.h"

/********************************************************************* 
* Function: main
* Description: Plays the game using the gameCycle function
* Parameters: N/A
* Pre-Conditions: The program has begun
* Post-Conditions: The game is either exited upon user request or has been lost
*********************************************************************/ 
int main(){
	Zoo my_zoo;
	
	int keep_playing;
	bool bank_empty;
	do{
		bank_empty = true;
		keep_playing = 2;
		my_zoo.gameCycle(bank_empty);
		if(bank_empty == true){
			cout << "You're broke. The zoo closes. Everything is terrible." << endl;
			break;
		}
		else{
			cout << endl << "Do you want to keep playing? [1] Yes [2] No: ";
			bool valid_input;
			string s;
			do{ //verify that their input is valid; loops until the input is either a 1 or a 2
				valid_input = true;
				getline(cin, s);
				keep_playing = atoi(s.c_str());
				if(keep_playing < 1 || keep_playing > 2){
					cout << "Invalid input. ";
					valid_input = false;
				}
			}while(valid_input == false);
		}
	}while(keep_playing == 1);

	return 0;
}
