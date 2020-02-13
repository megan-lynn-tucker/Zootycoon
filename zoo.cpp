/********************************************************************
* Program Filename: zoo.cpp
* Author: Megan Lynn Tuker
* Date: 02/16/2020
* Description: Performs all operations involved in running the zoo
* Input: N/A
* Output: N/A
*********************************************************************/
 
#include<iostream>
#include<cstdlib> //srand(), rand(), atoi()
#include<cstddef> //NULL
#include<stdio.h> //printf
#include"zoo.h"
#include"animal.h"
#include"sea_lion.h"
#include"bear.h"
#include"tiger.h"

using namespace std;
 
/********************************************************************* 
* Function: Zoo
* Description: Constructor
* Parameters: N/A
* Pre-Conditions: A zoo object is created
* Post-Conditions: The default values are set; the dynamic arrays of animals are set to null
*********************************************************************/ 
Zoo::Zoo(){
	sea_lions = NULL;
	n_sea_lions = 0;
	n_pur_sea_lions = 0;
	bears = NULL;
	n_bears = 0;
	n_pur_bears = 0;
	tigers = NULL;
	n_tigers = 0;
	n_pur_tigers = 0;
	bank = 100000.00;
	base = 80.00;
}

/********************************************************************* 
* Function: Zoo
* Description: Copy Constructor
* Parameters: Zoo object
* Pre-Conditions: An zoo object is to be copied; Zoo a; Zoo b = a;
* Post-Conditions: The zoo object is coppied
*********************************************************************/ 
Zoo::Zoo(const Zoo& old_zoo){
	bank = old_zoo.bank;
	//note that the arrays require for loops to copy over the values

	n_sea_lions = old_zoo.n_sea_lions;
	n_pur_sea_lions = old_zoo.n_pur_sea_lions;
	sea_lions = new Sea_lion[n_sea_lions];
	for(int i = 0; i < n_sea_lions; i++){
		sea_lions[i] = old_zoo.sea_lions[i];
	}

	n_bears = old_zoo.n_bears;
	n_pur_bears = old_zoo.n_pur_bears;
	bears = new Bear[n_bears];
	for(int i = 0; i < n_bears; i++){
		bears[i] = old_zoo.bears[i];
	}

	n_tigers = old_zoo.n_tigers;
	n_pur_tigers = old_zoo.n_pur_tigers;
	tigers = new Tiger[n_tigers];
	for(int i = 0; i < n_tigers; i++){
		tigers[i] = old_zoo.tigers[i];
	}
}

/********************************************************************* 
* Function: operator=
* Description: Assignment Operator Overload
* Parameters: Zoo object
* Pre-Conditions: A zoo object is to be copied; Zoo a; Zoo b; b = a
* Post-Conditions: The zoo object is coppied
*********************************************************************/ 
Zoo& Zoo::operator=(const Zoo old_zoo){
	bank = old_zoo.bank;
	
	n_sea_lions = old_zoo.n_sea_lions;
	n_pur_sea_lions = old_zoo.n_pur_sea_lions;
	sea_lions = new Sea_lion[n_sea_lions];
	for(int i = 0; i < n_sea_lions; i++){
		sea_lions[i] = old_zoo.sea_lions[i];
	}

	n_bears = old_zoo.n_bears;
	n_pur_bears = old_zoo.n_pur_bears;
	bears = new Bear[n_bears];
	for(int i = 0; i < n_bears; i++){
		bears[i] = old_zoo.bears[i];
	}

	n_tigers = old_zoo.n_tigers;
	n_pur_tigers = old_zoo.n_pur_tigers;
	tigers = new Tiger[n_tigers];
	for(int i = 0; i < n_tigers; i++){
		tigers[i] = old_zoo.tigers[i];
	}

	return *this;
}

/********************************************************************* 
* Function: printZoo
* Description: Prints the current state of the zoo
* Parameters: N/A
* Pre-Conditions: N/A
* Post-Conditions: N/A
*********************************************************************/ 
void Zoo::printZoo(){
	int num_adults = 0;
	int num_babies = 0; 

	cout << endl << "Bank: $";
	printf("%.2f", bank); //ensures the bank is printed to two decimal places
	cout << endl << endl;
	
	cout << "Total SEA LIONS: " << n_sea_lions << endl;
	for(int i = 0; i < n_sea_lions; i++){
		if(sea_lions[i].getAge() < 6){
			++num_babies;
		}
		else if(sea_lions[i].getAge() >= 48){
			++num_adults;

		}
	}
	printInfo(num_babies, num_adults);
	
	cout << "Total BEARS: " << n_bears << endl;
	for(int i = 0; i < n_bears; i++){
		if(bears[i].getAge() < 6){
			++num_babies;
		}
		else if(bears[i].getAge() >= 48){
			++num_adults;
		}
	}
	printInfo(num_babies, num_adults);

	cout << "Total TIGERS: " << n_tigers << endl;
	for(int i = 0; i < n_tigers; i++){
		if(tigers[i].getAge() < 6){
			++num_babies;
		}
		else if(tigers[i].getAge() >= 48){
			++num_adults;
		}
	}
	printInfo(num_babies, num_adults);
}

/********************************************************************* 
* Function: printInfo
* Description: Print the number of babies and adults for a particular species
* Parameters: int number of babies and int number of adults
* Pre-Conditions: The number of adults and babies of a particular species is determined
* Post-Conditions: The numbers are printed and are reset to zero
*********************************************************************/ 
void Zoo::printInfo(int &num_babies, int &num_adults){
	cout << "Babies: " << num_babies << endl;
	cout << "Adults: " << num_adults << endl << endl;
	num_adults = 0;
	num_babies = 0; 
}

/********************************************************************* 
* Function: checkInput
* Description: Check that the user input is valid
* Parameters: int selection of choice
* Pre-Conditions: The user is prompted to make a selection
* Post-Conditions: The selection is valid
*********************************************************************/ 
void Zoo::checkInput(int &selection){
	bool valid_input;
	string s;
	do{ //verify that their input is valid; loops until the input is between 1 and 4
		valid_input = true;
		getline(cin, s);
		selection = atoi(s.c_str());
		if(selection < 1 || selection > 4){
			cout << "Invalid input. ";
			valid_input = false;
		}
	}while(valid_input == false);
}

/********************************************************************* 
* Function: buyAnimal
* Description: The user chooses which animal (if any) to be purchased
* Parameters: N/A
* Pre-Conditions: The buy animal phase of the game play occurs
* Post-Conditions: An valid choice of animal has been made
*********************************************************************/ 
void Zoo::buyAnimal(){
	if(n_pur_sea_lions == 2 && n_pur_bears == 2 && n_pur_tigers == 2){
		cout << endl << "You have already bought two of every type of animal." << endl;
	}
	else if(bank < 700){
		cout << "You do not have enough money to buy any animals." << endl;
	}
	else{
		cout << endl << "Which animal do you want to buy? ";
		cout << "[1] sea lion $700 [2] bear $5000 [3] tiger $12000 [4] NONE: ";
		bool can_buy;
		int selection;
		do{ //run this loop until they select a species for which they have not bought 2 of
			can_buy = true;
			checkInput(selection);
			if(selection == 1){
				if(n_pur_sea_lions == 2){
					cout << "You have already bought two sea lions. Select another animal." << endl;
					can_buy = false;
				}
				else{
					Sea_lion new_sea_lion;
					addSea_lion(new_sea_lion);
					sea_lions[n_sea_lions - 1].setAge(48); //purchased animals are adults
					n_pur_sea_lions++;
					bank = bank - sea_lions[0].getPrice(); //remove money from bank
				}
			}
			else if(selection == 2){
				if(n_pur_bears == 2){
					cout << "You have already bought two bears. Select another animal." << endl;
					can_buy = false;
				}
				else if(bank < 5000){
					cout << "You don't have enough money. Buy a different animal." << endl;
				}
				else{
					Bear new_bear;
					addBear(new_bear);
					bears[n_bears - 1].setAge(48);
					n_pur_bears++;
					bank = bank - bears[0].getPrice();
				}
			}
			else if(selection == 3){
				if(n_pur_tigers == 2){
					cout << "You have already bought two tigers. Select another animal." << endl;
					can_buy = false;
				}
				else if(bank < 12000){
					cout << "You don't have enough money. Buy a different animal." << endl;
				}
				else{
					Tiger new_tiger;
					addTiger(new_tiger);
					tigers[n_tigers - 1].setAge(48);
					n_pur_tigers++;
					bank = bank - tigers[0].getPrice();
				}
			}
			else{
				break;
			}
		}while(can_buy == false);
	}
}

/********************************************************************* 
* Function: addSea_lion
* Description: Adds a new sea lion to the array of sea lions
* Parameters: new Sea_lion object to be added
* Pre-Conditions: The user bought a sea lion or a sea lion was born
* Post-Conditions: The array was increased by 1 and the new sea lion added
*********************************************************************/ 
void Zoo::addSea_lion(Sea_lion &new_sea_lion){
	if(n_sea_lions == 0){ //check if the array exists; if not it is the start of the game
		sea_lions = new Sea_lion[1]; //create an array of size 1
		sea_lions[0] = new_sea_lion;
		++n_sea_lions;
	}
	else{
		++n_sea_lions;
		Sea_lion *temp = new Sea_lion[n_sea_lions];
		for(int i = 0; i < n_sea_lions; i++){
			if(i == n_sea_lions - 1){ //if we are at the last value in the array
				temp[i] = new_sea_lion;
			}
			else{
				temp[i] = sea_lions[i]; //copy the value of cards into temp
			}
		}
	delete [] sea_lions; //delete the old array
	sea_lions = temp; //make the pointer for sea lions point to temp; no need to derefference 
	temp = NULL;
	}
}

/********************************************************************* 
* Function: addBear
* Description: Adds a new bear to the array of bears
* Parameters: new Bear object to be added
* Pre-Conditions: The user bought a bear  or a bear was born
* Post-Conditions: The array was increased by 1 and the new bear added
*********************************************************************/ 
void Zoo::addBear(Bear &new_bear){
	if(n_bears == 0){ //check if the array exists; if not it is the start of the game
		bears = new Bear[1]; //create an array of size 1
		bears[0] = new_bear;
		++n_bears;
	}
	else{
		++n_bears;
		Bear *temp = new Bear[n_bears];
		for(int i = 0; i < n_bears; i++){
			if(i == n_bears - 1){ //if we are at the last value in the array
				temp[i] = new_bear;
			}
			else{
				temp[i] = bears[i]; //copy the value of cards into temp
			}
		}
	delete [] bears; //delete the old array
	bears = temp; //make the pointer for bear point to temp; no need to derefference 
	temp = NULL;
	}
}

/********************************************************************* 
* Function: addTiger
* Description: Adds a new tiger to the array of tigers
* Parameters: new Tiger object to be added
* Pre-Conditions: The user bought a tiger or a sea lion was born
* Post-Conditions: The array was increased by 1 and the new tiger  added
*********************************************************************/ 
void Zoo::addTiger(Tiger &new_tiger){
	if(n_tigers == 0){ //check if the array exists; if not it is the start of the game
		tigers = new Tiger[1]; //create an array of size 1
		tigers[0] = new_tiger;
		++n_tigers;
	}
	else{
		++n_tigers;
		Tiger *temp = new Tiger[n_tigers];
		for(int i = 0; i < n_tigers; i++){
			if(i == n_tigers - 1){ //if we are at the last value in the array
				temp[i] = new_tiger;
			}
			else{
				temp[i] = tigers[i]; //copy the value of cards into temp
			}
		}
	delete [] tigers; //delete the old array
	tigers = temp; //make the pointer for bear point to temp; no need to derefference 
	temp = NULL;
	}
}

/********************************************************************* 
* Function: removeSea_lion
* Description: Removes a sea lion to the array of sea lions
* Parameters: int location of the sea lion to be removed
* Pre-Conditions: A sea lion is sick and dies
* Post-Conditions: The array is decreased by 1 and the particular sea lion removed
*********************************************************************/ 
void Zoo::removeSea_lion(int &sea_lion_location){
	if (n_sea_lions == 0) { //ensure that n is never -1
		return;
	}
	--n_sea_lions; //change the total number of sea lions
	if(n_sea_lions == 0){
		delete [] sea_lions; //delete the old array
		sea_lions = NULL;
	}
	else{
		Sea_lion *temp = new Sea_lion[n_sea_lions];
		for(int i = 0; i < n_sea_lions; i++){
			if(i >= sea_lion_location){
				temp[i] = sea_lions[i + 1]; //skip the sea lion to be removed
			}
			else{
				temp[i] = sea_lions[i]; //copy the values of sea lion into temp
			}
		}
		delete [] sea_lions; //delete the old array
		sea_lions = temp; //make the pointer for sea lions point to temp; no need to derefference 
		temp = NULL;
	}
}

/********************************************************************* 
* Function: removeBear
* Description: Removes a bear to the array of bear
* Parameters: int location of the bear to be removed
* Pre-Conditions: A bear is sick and dies
* Post-Conditions: The array is decreased by 1 and the particular bear removed
*********************************************************************/ 
void Zoo::removeBear(int &bear_location){
	if (n_bears == 0) { //ensure that n is never -1
		return;
	}
	--n_bears; //change the total number of bears
	if(n_bears == 0){
		delete [] bears; //delete the old array
		bears = NULL;
	}
	else{
		Bear *temp = new Bear[n_bears];
		for(int i = 0; i < n_bears; i++){
			if(i >= bear_location){
				temp[i] = bears[i + 1]; //skip the bear to be removed
			}
			else{
				temp[i] = bears[i]; //copy the values of bear into temp
			}
		}
		delete [] bears; //delete the old array
		bears = temp; //make the pointer for bears point to temp; no need to derefference 
		temp = NULL;
	}
}

/********************************************************************* 
* Function: removeTiger
* Description: Removes a tiger to the array of bear
* Parameters: int location of the tiger to be removed
* Pre-Conditions: A tiger is sick and dies
* Post-Conditions: The array is decreased by 1 and the particular tiger removed
*********************************************************************/ 
void Zoo::removeTiger(int &tiger_location){
	if (n_tigers == 0) { //ensure that n is never -1
		return;
	}
	--n_tigers; //change the total number of tigers
	if(n_tigers == 0){
		delete [] tigers; //delete the old array
		tigers = NULL;
	}
	else{
		Tiger *temp = new Tiger[n_tigers];
		for(int i = 0; i < n_tigers; i++){
			if(i >= tiger_location){
				temp[i] = tigers[i + 1]; //skip the tiger to be removed
			}
			else{
				temp[i] = tigers[i]; //copy the values of tiger into temp
			}
		}
		delete [] tigers; //delete the old array
		tigers = temp; //make the pointer for tiger point to temp; no need to derefference 
		temp = NULL;
	}
}

/********************************************************************* 
* Function: increaseAge
* Description: The age of each animal is increased
* Parameters: N/A
* Pre-Conditions: The increase age part of the game cycle occurs
* Post-Conditions: The age of each animal is increased by 1 month
*********************************************************************/ 
void Zoo::increaseAge(){ 
	if(n_sea_lions > 0){ //only increase the age of the animal if there exists an array
		for(int i = 0; i < n_sea_lions; i++){
			sea_lions[i].increaseAge();
		}
	}
	if(n_bears > 0){
		for(int i = 0; i < n_bears; i++){
			bears[i].increaseAge();
		}
	}
	if(n_tigers > 0){
		for(int i = 0; i < n_tigers; i++){
			tigers[i].increaseAge();
		}
	}
}

/********************************************************************* 
* Function: randEvent
* Description: A random event is selected
* Parameters: N/A
* Pre-Conditions: The random event portion of the game cycle occurs 
* Post-Conditions: A random event which is possible occurs
*********************************************************************/ 
void Zoo::randEvent(){
	if(n_sea_lions == 0 && n_bears == 0 && n_tigers == 0){
		cout << "You have no animals. This zoo sucks." << endl;
	}
	else{
		bool can_occur;
		do{ //note that this dowhile makes the program sometimes take longer
			can_occur = true;
			int event;
			srand(time(NULL));
			event = rand() % 3;
			if(event == 0){ //just need to have one animal of some species; contition is checked above
				sick();
			}
			else if(event == 1){ //check that at least one species has two adults
				if(n_sea_lions >= 2 || n_bears >= 2 || n_tigers >= 2){
					birth();
				}
				else{
					can_occur = false;
				}
			}
			else if(event == 2){
				if(n_sea_lions != 0){
					float old_bank = bank;
					for(int i = 0; i < n_sea_lions; i++){
						//each sea lion generates a different bonus revenue
						bank = bank + sea_lions[i].attendanceBoom(); 
					}
					old_bank = bank - old_bank;
					cout << "There is an attendance boom and sea lions generate an extra $";
					cout << old_bank << "." << endl;
				}
				else{
					can_occur = false;
				}
			}
		}while(can_occur == false);
	}
}

/********************************************************************* 
* Function: sick
* Description: Choose an species and an animal to get sick
* Parameters: N/A
* Pre-Conditions: The random event chosen was sick
* Post-Conditions: The animal either dies or the correct amount is deducted from the bank
*********************************************************************/ 
void Zoo::sick(){	
	bool have_species;
	do{
		have_species = true;
		int species;
		srand(time(NULL));
		species = rand() % 3;
		if(species == 0){
			if(n_sea_lions == 0){
				have_species = false;
			}
			else{
				sickSea_lion();
			}
		}
		else if(species == 1){
			if(n_bears == 0){
				have_species = false;
			}
			else{
				sickBear();
			}
		}
		else if(species == 2){
			if(n_tigers == 0){
				have_species = false;
			}
			else{
				sickTiger();
			}
		}
	}while(have_species == false);
}

/********************************************************************* 
* Function: sickSea_lion
* Description: Checks if the sea lion is an adult or baby; either deducts money or removes animal
* Parameters: N/A
* Pre-Conditions: A sea lion was chosen to be sick
* Post-Conditions: That sea lion is either removed or the money is removed
*********************************************************************/ 
void Zoo::sickSea_lion(){
	cout << "A sea lion is sick! ";
	int sick_sea_lion;
	srand(time(NULL));
	sick_sea_lion = rand() % n_sea_lions;
	if(sea_lions[sick_sea_lion].getAge() < 6){
		cout << "It's a baby!! ";
		if(bank >= sea_lions[sick_sea_lion].getPrice()){
			cout << "You pay $" << sea_lions[sick_sea_lion].getPrice() << " to save it." << endl;
			bank = bank - (sea_lions[sick_sea_lion].getPrice());
		}
		else if(bank < sea_lions[sick_sea_lion].getPrice()){
			cout << "You don't have any money and it dies. Nice job." << endl;
			removeSea_lion(sick_sea_lion);	
		}
	}
	else{
		if(bank >= (sea_lions[sick_sea_lion].getPrice())/2){
			cout << "You pay $" << (sea_lions[sick_sea_lion].getPrice())/2 << " to save it." << endl;
			bank = bank - ((sea_lions[sick_sea_lion].getPrice())/2);
		}
		else if(bank < (sea_lions[sick_sea_lion].getPrice())/2){
			cout << "You don't have any money and it dies. Nice job." << endl;
			removeSea_lion(sick_sea_lion);	
		}
	}
}

/********************************************************************* 
* Function: sickBear
* Description: Checks if the bear is an adult or baby; either deducts money or removes animal
* Parameters: N/A
* Pre-Conditions: A bear was chosen to be sick
* Post-Conditions: That bear is either removed or the money is removed
*********************************************************************/ 
void Zoo::sickBear(){
	cout << "A bear is sick! ";
	int sick_bear;
	srand(time(NULL));
	sick_bear = rand() % n_bears;
	if(bears[sick_bear].getAge() < 6){
		cout << "It's a baby!! ";
		if(bank >= bears[sick_bear].getPrice()){
			cout << "You pay $" << bears[sick_bear].getPrice() << " to save it." << endl;
			bank = bank - (bears[sick_bear].getPrice());
		}
		else if(bank < bears[sick_bear].getPrice()){
			cout << "You don't have any money and it dies. Nice job." << endl;
			removeBear(sick_bear);	
		}
	}
	else{
		if(bank >= (bears[sick_bear].getPrice())/2){
			cout << "You pay $" << (bears[sick_bear].getPrice())/2 << " to save it." << endl;
			bank = bank - ((bears[sick_bear].getPrice())/2);
		}
		else if(bank < (bears[sick_bear].getPrice())/2){
			cout << "You don't have any money and it dies. Nice job." << endl;
			removeBear(sick_bear);	
		}
	}
}

/********************************************************************* 
* Function: sickTiger
* Description: Checks if the tiger is an adult or baby; either deducts money or removes animal
* Parameters: N/A
* Pre-Conditions: A tiger was chosen to be sick
* Post-Conditions: That tiger is either removed or the money is removed
*********************************************************************/ 
void Zoo::sickTiger(){
	cout << "A tiger is sick! ";
	int sick_tiger;
	srand(time(NULL));
	sick_tiger = rand() % n_tigers;
	if(tigers[sick_tiger].getAge() < 6){
		cout << "It's a baby!! ";
		if(bank >= tigers[sick_tiger].getPrice()){
			cout << "You pay $" << tigers[sick_tiger].getPrice() << " to save it." << endl;
			bank = bank - (tigers[sick_tiger].getPrice());
		}
		else if(bank < tigers[sick_tiger].getPrice()){
			cout << "You don't have any money and it dies. Nice job." << endl;
			removeSea_lion(sick_tiger);	
		}
	}
	else{
		if(bank >= (tigers[sick_tiger].getPrice())/2){
			cout << "You pay $" << (tigers[sick_tiger].getPrice())/2 << " to save it." << endl;
			bank = bank - ((tigers[sick_tiger].getPrice())/2);
		}
		else if(bank < (tigers[sick_tiger].getPrice())/2){
			cout << "You don't have any money and it dies. Nice job." << endl;
			removeTiger(sick_tiger);	
		}
	}
}

/********************************************************************* 
* Function: birth
* Description: Checks if the sea lion is an adult or baby; either deducts money or removes animal
* Parameters: N/A
* Pre-Conditions: The birth event was randomly chosen
* Post-Conditions: A baby is born 
*********************************************************************/ 
void Zoo::birth(){
	bool have_two_adults;
	do{ //run the dowhile until a species is selected which has two adult animals
		have_two_adults = true;
		int species;
		srand(time(NULL));
		species = rand() % 3;
		int n_adults = 0;
		if(species == 0){
			for(int i = 0; i < n_sea_lions; i++){
				if(sea_lions[i].getAge() >= 48){
					++n_adults;
				}
			}
			if(n_adults < 2){
				have_two_adults = false;
			}
			else{
				cout << "A baby sea lion is born!" << endl;
				Sea_lion baby_sea_lion;
				addSea_lion(baby_sea_lion);
			}
		}
		else if(species == 1){
			for(int i = 0; i < n_bears; i++){
				if(bears[i].getAge() >= 48){
					++n_adults;
				}
			}
			if(n_adults < 2){
				have_two_adults = false;
			}
			else{
				cout << "A baby bear is born!" << endl;
				Bear baby_bear;
				addBear(baby_bear);
			}
		}
		else if(species == 2){
			for(int i = 0; i < n_tigers; i++){
				if(tigers[i].getAge() >= 48){
					++n_adults;
				}
			}
			if(n_adults < 2){
				have_two_adults = false;
			}
			else{
				cout << "A baby tiger is born!" << endl;
				Tiger baby_tiger;
				addTiger(baby_tiger);
			}
		}
	}while(have_two_adults == false);
}

/********************************************************************* 
* Function: checkBank
* Description: Checks if the bank is empty or not
* Parameters: bool is the bank empty
* Pre-Conditions: Money was withdrawn from the bank
* Post-Conditions: The state of the bank is returned
*********************************************************************/ 
void Zoo::checkBank(bool &bank_empty){
	if(bank < 0){
		bank_empty = true;
	}
	else{
		bank_empty = false;
	}
}

/********************************************************************* 
* Function: generateRevenue
* Description: Revenue is generated from the animals present 
* Parameters: N/A
* Pre-Conditions: The generate revenue portion of the game cycle occurs
* Post-Conditions: The bank is increased by the amount of revenue generated
*********************************************************************/ 
void Zoo::generateRevenue(){
	float old_bank = bank;
	for(int i = 0; i < n_sea_lions; i++){
		if(sea_lions[i].getAge() < 6){
			bank = bank + (2*sea_lions[i].getPrice());
		}
		else{
			bank = bank + sea_lions[i].getPrice();
		}
	}
	for(int i = 0; i < n_bears; i++){
		if(bears[i].getAge() < 6){
			bank = bank + (2*bears[i].getPrice());
		}
		else{
			bank = bank + bears[i].getPrice();
		}
	}
	for(int i = 0; i < n_tigers; i++){
		if(tigers[i].getAge() < 6){
			bank = bank + (2*tigers[i].getPrice());
		}
		else{
			bank = bank + tigers[i].getPrice();
		}
	}
	old_bank = bank - old_bank;
	cout << endl << "The zoo makes $" << old_bank << "." << endl;
}

/********************************************************************* 
* Function: feedAnimals
* Description: Deduct money based off of species food requiremnets
* Parameters: N/A
* Pre-Conditions: The feed animals portion of the game cycle occurs
* Post-Conditions: The appropriate amount of money is deducted from the bank
*********************************************************************/ 
void Zoo::feedAnimals(){	
	if(n_sea_lions > 0 || n_bears > 0 || n_tigers > 0){
		float old_bank = bank;
		float base_change;
		srand(time(NULL));
		base_change = (float(rand() % 5) + 8.0)/10.0;
		base = base*base_change;
		for(int i = 0; i < n_sea_lions; i++){
			if(n_sea_lions > 0){
				bank = bank - base;
			}
		}
		for(int i = 0; i < n_bears; i++){
			if(n_bears > 0){
				bank = bank - (base*bears[i].getFood());
			}
		}
		for(int i = 0; i < n_tigers; i++){
			if(n_tigers > 0){
				bank = bank - (base*tigers[i].getFood());
			}
		}
		old_bank = old_bank - bank;
		cout << endl << "The zoo pays $" << old_bank << " for food." << endl;
	}
}

/********************************************************************* 
* Function: gameCycle
* Description: Runs through the game cycle: increase age, random event, revenue, feed animals
* Parameters: bool is the bank empty
* Pre-Conditions: The game is in play
* Post-Conditions: Either the function runs through completely or exits upon finding the bank empty
*********************************************************************/ 
void Zoo::gameCycle(bool &bank_empty){
	printZoo();
	cout << "All animals age one month." << endl;
	increaseAge();
	cout << endl << "A random event occurs!" << endl;
	randEvent();
	checkBank(bank_empty);
	if(bank_empty == true){
		return;
	}
	generateRevenue();
	buyAnimal();
	checkBank(bank_empty);
	if(bank_empty == true){
		return;
	}
	feedAnimals();
	checkBank(bank_empty);
	if(bank_empty == true){
		return;
	}
	bank_empty = false; //if it made it all the way through set this to false just in case
}

/********************************************************************* 
* Function: ~Zoo
* Description: Deletes dynamic memory
* Parameters: N/A
* Pre-Conditions: Zoo object falls out of scope
* Post-Conditions: The arrays are deleted
*********************************************************************/ 
Zoo::~Zoo(){
	delete [] sea_lions;
	delete [] bears;
	delete [] tigers;
}
