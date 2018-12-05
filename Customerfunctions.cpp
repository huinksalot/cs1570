//Programmer: Benjamin Huinker
//Section: F
//File: customerfunctions.cpp
//Purpose: Overrides class functions within hw9.h

using namespace std;
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include "Customer.h"
#include "Burger.h"
#include "Burgermeister.h"

//CUSTOMER MEMBER FUNCTIONS

//DEFAULT CONSTRUCTOR
Customer::Customer()
{
  setName();
  setMoney();
  setWeight();
  setLiving();
  setCholesterol();
  setHealth();
  setContestant();
  setEaten();
  setStatus();
}


void Customer::setName()
{
  ifstream in;
  static int line = 1;
  in.open("simpson_names.dat");
  //Sets the name from the simpsons name file
  for(int i = 0; i < line; i++)
  {
    in.getline(m_name, 30);
  }
  line++;
  return;
}

void Customer::tryEat(Burgermeister  & krusty, int spot, Customer conts[])
{
  Burger burg;
  //If everything is good they will eat,
  // if not it will print off what is wrong and change status to 0
  if(m_money >= burg.getPrice() && m_health > 0 && m_contestant)
  {
    eat(burg, krusty, spot, conts);
  }
  else if(m_money < burg.getPrice())
  {
    cout << m_name << " can't afford to eat!" << endl;
    m_status = 0;
  }
  else if(m_health <= 0 )
  {
    cout << m_name << " is dead!" << endl;
    m_status = 0;
    m_isLiving = 0;
  }
  else if(!m_contestant)
  {
    cout << m_name << " is disqualified!" << endl;
    m_status = 0;
  }
  return;
}

void Customer::eat(const Burger burg, Burgermeister  & krusty
                   , int spot, Customer conts[])
{
  const float PI = 3.14;
  const int PUKE = rand()%101;

   cout << m_name << " eats a burger" ;
  //Cholesterol gain equation
  m_cholesterol += (2.5*burg.getBacon()) + ((PI/2)*burg.getPatty())
                   + (m_weight/((burg.getPickle()+1)*10));
  //Weight gain equation
  m_weight += (.5 * pow(burg.getPatty(), 2)) + static_cast<float>(1/8)
              *pow(burg.getBacon(),2) - static_cast<float>(burg.getPickle())/4
              + (burg.getCheese()*1.2) + (burg.getSauce()*2.1);
  m_health -= 2;
  //Deducts the cost of the burger from their current wallet amount
  m_money -= burg.getPrice();
  krusty += burg.getPrice();
  m_totEaten += 1;
  //Changes to DEAD if they eat a burger with a virulent pathogen
  if(burg.getVirus() == 1)
  {
    if (PUKE > m_health)
    {
      m_isLiving = 0;
      m_health = 0;
      m_contestant = 0;
      krusty -= 35;
      cout << " and DIES." << endl;
    }
    else
    {
      cout << " and barfs!" << endl;
      krusty -= 5;
      m_health /= 2;
      if (spot == 14)
      {
        //If they're at the top of the array, it will only go down
        pukeDown(krusty, spot, conts);

      }
      else if (spot == 0)
      {
        //If they're at the bottom of the array, it will only go up
        pukeUp(krusty, spot, conts);        
      }
      else
      {
        //If they're in the middle, it will do both directions
        pukeDown(krusty, spot, conts);
        pukeUp(krusty, spot, conts);
      }
    }
  }
  else
  {
    cout << endl;
  }
  return;
}

void Customer::pukeDown(Burgermeister & krusty, int spot, Customer conts[])
{
  //Calculates a chance and uses recursion to walk down the array
  int chance;
  m_health /= 2;
  chance = rand()%100;
  if (chance > 50)
  {
    if (spot != 0 && conts[spot - 1].getLiving())
    {
      cout << "\t" << conts[spot - 1].getName()
           << " pukes... ARFGHEREHGJFDSGFDS" << endl;
      krusty -= 5;
      conts[spot - 1].pukeDown(krusty, spot - 1, conts);
    }
    else if(!conts[spot-1].getLiving())
    {
      cout << "\t" << conts[spot-1].getName()
           << " can't puke from the grave" << endl;
    }
  }
  else
  {
    cout << "\t" << conts[spot - 1].getName() << " doesn't puke" << endl;
    //70% chance for the person who doesn't puke to start a food fight
    chance = rand()%100;
    if (chance < 70)
    {
      conts[spot-1].toss(krusty, conts);
    }
  }
  return;
}

void Customer::pukeUp(Burgermeister & krusty, int spot, Customer conts[])
{
  //Same as pukeDown only in reverse order
  int chance;
  m_health /= 2;
  chance = rand()%100;
  if (chance > 50)
  {
    if (spot != 14 && conts[spot + 1].getLiving())
    {
      cout << "\t" << conts[spot + 1].getName()
           << " pukes... ARFGHEREHGJFDSGFDS" << endl;
      krusty -= 5;
      conts[spot + 1].pukeUp(krusty, spot + 1, conts);
    }
    else if(!conts[spot+1].getLiving())
    {
      cout << "\t" << conts[spot+1].getName()
           << " can't puke from the grave" << endl;
    }
  }
  else
  {
    cout << "\t" << conts[spot + 1].getName() << " doesn't puke" << endl;
    chance = rand()%100;
    if (chance < 70)
    {
      conts[spot+1].toss(krusty, conts);
    }
  }
  return;
}

void Customer::toss(Burgermeister & krusty, Customer conts[])
{
  //0-14 is another contestant, 15 is Krusty
  int tossedAt = rand()%16;
  int chance;
  Burger burg;
  if (tossedAt == 15)
  {
    //Gives their money to Krusty and DQs them
    cout << "\t\t" << m_name << " throws a burger at Krusty!" << endl;
    krusty += m_money;
    m_money = 0;
    m_contestant = 0;
  }
  else
  {
    //Pay for the burger and gain 2 health,
    // uses recursion to continue the foodfight
    cout << "\t\t" << m_name << " throws a burger at "
         << conts[tossedAt].getName() << endl;
    m_money -= burg.getPrice();
    m_health += 2;
    chance = rand()%100;
    if (chance < 80)
    {
      conts[tossedAt].toss(krusty, conts);
    }
    else
    {
      cout << "\t\t" << conts[tossedAt].getName()
           << " doesn't throw a burger." << endl;
    }
  }
  return;
}

//Allows for printing of class Customer
ostream& operator <<(ostream& os, Customer cust)
{
  os << cust.getName() << " weighs " << cust.getWeight() << " lbs, has $"
       << cust.getMoney() << ", "
       << cust.getCholesterol() << " IBU and is "
       << (cust.getLiving()?"ALIVE":"DEAD") 
       << endl;
   return os;
}
