/********************************************************************
* Program Filename: bear.cpp
* Author: Megan Lynn Tucker
* Date: 02/16/2020
* Description: Creates a bear object
* Input: N/A
* Output: N/a
*********************************************************************/
 
#include<iostream>
#include<cstring>
#include"bear.h"

using namespace std;
 
/********************************************************************* 
* Function: Bear
* Description: Constructor
* Parameters: N/A
* Pre-Conditions: A bear object is constructed
* Post-Conditions: It is initialized to default bear conditions
*********************************************************************/ 
Bear::Bear(){
	setSpecies("bear");
	setAge(0);
	setPrice(5000);
	setBabies(2);
	setFood(3);
	setRevenue(500);
}

/********************************************************************* 
* Function: ~Bear
* Description: Destructor
* Parameters: N/A
* Pre-Conditions: A bear object falls out of scope
* Post-Conditions: It is destroyed
*********************************************************************/ 
Bear::~Bear(){ }
