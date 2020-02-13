/*********************************************************************
* Program Filename: zoo.h
* Author: Megan Lynn Tucker
* Date: 02/17/2020
***********************************************************************/
#ifndef ZOO_H
#define ZOO_H

#include<iostream>
#include"sea_lion.h"
#include"bear.h"
#include"tiger.h"

class Zoo{
	private:
		Sea_lion *sea_lions; //dynamic array of sea lions
		int n_sea_lions;
		int n_pur_sea_lions; //counter for how many adults have been purchased; max = 2
		Bear *bears; //dynamic array of bears
		int n_bears; 
		int n_pur_bears;
		Tiger *tigers; //dynamic array of tigers
		int n_tigers;
		int n_pur_tigers;
		float bank;
		float base; //base food price
	public: //Note: getters and setters are unnecessary as all functions run through zoo class
		Zoo();
		Zoo(const Zoo&); //copy constructor
		Zoo& operator= (const Zoo); //assignment operator overload

		void printZoo();
		void printInfo(int&, int&); //input is the number of babies and adults of a particular species
		
		void checkInput(int&); //input is the selection number
		void buyAnimal();
		
		//input is always the new animal to be added
		void addSea_lion(Sea_lion&);
		void addBear(Bear&);
		void addTiger(Tiger&);
		//input is the locatin in the array to be removed
		void removeSea_lion(int&);
		void removeBear(int&);
		void removeTiger(int&);

		void increaseAge();
		void randEvent();
		void sick();
		void sickSea_lion();
		void sickBear();
		void sickTiger();
		void birth();
		void checkBank(bool&);
		void generateRevenue();
		void feedAnimals();

		void gameCycle(bool&); //changes the value of bank_empty
		~Zoo();
};
#endif 
