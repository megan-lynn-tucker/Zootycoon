/********************************************************************
* Program Filename: tiger.cpp
* Author: Megan Lynn Tucker
* Date: 02/16/2020
* Description: Generates a tiger object
* Input: N/A
* Output: N/A
*********************************************************************/
 
#include<iostream>
#include<cstring>
#include"tiger.h"

using namespace std;
 
/********************************************************************* 
* Function: Tiger
* Description: Constructor
* Parameters: N/A
* Pre-Conditions: A tiger object is constructed
* Post-Conditions: It is initialized to default tiger conditions
*********************************************************************/ 
Tiger::Tiger(){
	setSpecies("tiger");
	setAge(0);
	setPrice(12000);
	setBabies(3);
	setFood(5);
	setRevenue(1200);
}

/********************************************************************* 
* Function: ~Tiger
* Description: Destructor
* Parameters: N/A
* Pre-Conditions: An tiger object falls out of scope
* Post-Conditions: It is destroyed
*********************************************************************/ 
Tiger::~Tiger(){ }
