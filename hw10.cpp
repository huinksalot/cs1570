//Programmer: Benjamin Huinker
//Section: F
//File: hw9.cpp
//Purpose: Simulates a burger eating contest

using namespace std;
#include <iostream>
#include <ctime>
#include "Burger.h"
#include "Customer.h"
#include "Burgermeister.h"
#include "hw10.h"

int main()
{
  cout.setf(ios::fixed); 
  cout.setf(ios::showpoint); //Only shows two decimal points in final print
  cout.precision(2);
  srand(time(NULL));
  
  int round = 0;
  
  Customer contestants[15]; //The initial contestants array
  Burgermeister Krusty;
  
  cout << "---------------" << endl;
  cout << "WELCOME TO TODAY'S COMPETITION (HOSTED BY KRUSTY CORP)" << endl;
  cout << "---------------" << endl;
  cout << "OUR CONTESTANTS ARE AS FOLLOWS: " << endl;
  for (int i = 0; i < 15; i++)
  {
    cout << contestants[i]; //Prints out the contestants and their stats
  }
  cout << "---------------" << endl;
  cout << endl;
  
  do
  {
    round++;
    cout << "----- Round #" << round << "-----" << endl;
    for (int i = 0; i < 15; i++)
    {
      //Calls tryEat which will branch off into puking or tossing accordingly
      contestants[i].tryEat(Krusty, i, contestants); 
    }
    cout << Krusty;
    cout << "---------------" << endl;
    cout << endl;
  }while(checkStandings(contestants));
  
  //Prints the winner
  declareWinner(contestants);
  //Goodbye message
  signOff(Krusty);
  return 0;
}