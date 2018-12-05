//Programmer: Benjamin Huinker
//Section: F
//File: hw10functions.cpp
//Purpose: Contains the functions used by the main file

#include "hw10.h"
#include "Burger.h"
using namespace std;

bool checkStandings(Customer conts[])
{
  bool nextRound = 0;
  //If any of the contestants status is true, the contest will keep going.
  for (int i = 0; i < 15; i++)
  {
    if (conts[i].getStatus() == true)
    {
      nextRound = 1;
    }
  }
  return nextRound;
}

void declareWinner(Customer conts[])
{
  int winnerIndex;
  int mostEaten = 0;
  //If the customer is living and a contestant, they will
  // be in the running for winning.
  //It will find the index in the array of the customer
  // with the most burgers eaten
  for (int i = 0; i < 15; i++)
  {
    if (conts[i].getLiving() == true && conts[i].getContestant() == true)
    {
      if (conts[i].getEaten() > mostEaten)
      {
        winnerIndex = i;
      }
    }
  }
  cout << "*********************************************" << endl;
  cout << "THE WINNER OF TODAY'S COMPETITION IS: " 
          << conts[winnerIndex].getName() << endl;
  return;
}

void signOff(Burgermeister krusty)
{
  cout << "But we all know the real winner here is Krusty Corp, "
          << " as they made $" << krusty.getMoney() - 100 << ". " << endl;
  cout << "Thank you for tuning in folks, I HOPE YOU DIDN'T GET SICK!" << endl;
  cout << "*********************************************" << endl;
  return;
}
