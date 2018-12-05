//Programmer: Benjamin Huinker
//Section: F
//File: hw10.h
//Purpose: Contains the declarations for functions of the competition

#ifndef HW10_H
#define HW10_H

#include "Customer.h"

//Desc: Checks every round if there are any valid contestants remaining
//Pre: Valid array passed
//Post: Returns false if no cont. are remaining
bool checkStandings(Customer conts[]);

//Desc: Sorts through the array for contestant with most burgers eaten
//Pre: Valid array passed
//Post: Prints out the winner of the contest
void declareWinner( Customer conts[]);

//Desc: Goodbye message, shows Krustys profit
//Pre: None
//Post: Prints a goodbye message
void signOff(Burgermeister krusty);

#endif