/********************************************************************
* Program Filename: sea_lion.cpp
* Author: Megan Lynn Tuker
* Date: 02/16/2020
* Description: Creates a sea lion object and functions associated
* Input: N/A
* Output: N/A
*********************************************************************/
 
#include<iostream>
#include<cstring>
#include<cstdlib> //srand(), rand(), atoi()
#include<cstddef> //NULL
#include"sea_lion.h"


using namespace std;
 
/********************************************************************* 
* Function: Sea_lion
* Description: Constructor
* Parameters: N/A
* Pre-Conditions: A sea lion object is constructed
* Post-Conditions: It is initialized to default sea lion conditions
*********************************************************************/ 
Sea_lion::Sea_lion(){
	setSpecies("sea lion");
	setAge(0);
	setPrice(700);
	setBabies(1);
	setFood(1);
	setRevenue(140);
}

/********************************************************************* 
* Function: attendanceBoom
* Description: Randomly generates the increased revenue generated by sea lions
* Parameters: N/A
* Pre-Conditions: The random event is that there is a boom in attendance
* Post-Conditions: Bonus revenue is returned
*********************************************************************/ 
float Sea_lion::attendanceBoom(){
	int bonus;
	srand(time(NULL));
	bonus = ((rand() % 26) + 15) * 10; //mod 26 privides numbers 0-25
	return bonus;
}

/********************************************************************* 
* Function: ~Sea_lion
* Description: Destructor
* Parameters: N/A
* Pre-Conditions: A sea lion object falls out of scope
* Post-Conditions: It is destroyed
*********************************************************************/ 
Sea_lion::~Sea_lion(){ }
