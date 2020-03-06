/*********************************************************************
* Program Filename: sea_lion.h
* Author: Megan Lynn Tucker
* Date: 02/17/2020
***********************************************************************/
#ifndef SEA_LION_H
#define SEA_LION_H

#include<iostream>
#include"animal.h"

class Sea_lion : public Animal {
	private:
	public:
		//static const int cost = 3500;
		//access this in driver using Sea_lion::cost
		//or if you have a Sea_lion object called my_sea_lion, access it using my_sea_lion.cost
	
		Sea_lion();
		float attendanceBoom();
		~Sea_lion();
};
#endif 
