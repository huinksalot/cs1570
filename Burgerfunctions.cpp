//Programmer: Benjamin Huinker
//Section: F
//File: burgerfunctions.cpp
//Purpose: Overrides class functions within hw9.h

using namespace std;
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Burger.h"

//BURGER MEMBER FUNCTIONS

//DEFAULT CONSTRUCTOR
Burger::Burger()
{
  setPatty();
  setBacon();
  setPickle();
  setCheese();
  setSauce();
  setVirus();
  setName();
}

//CONSTRUCTOR
Burger::Burger(const int p, const int b, const int pi, const int c
               , const int s, const int v)
{
  setPatty(p);
  setBacon(b);
  setPickle(pi);
  setCheese(c);
  setSauce(s);
  setVirus(v);
  setName();
}

//SETTER FUNCTIONS
void Burger::setName()
{
  const string BURGER = " Burger";
  const string KRUSTY = "Krusty";
  const string BURGERS1 = " Single";
  const string BURGERS2 = " Double";
  const string BURGERS3 = " Triple";
  const string BURGERS4 = " Quadro";
  const string BACON0 = " Health-Master";
  const string BACON1 = " Bacon";
  const string BACON2 = " Wilbur"; 
  const string BACON3 = " Klogger";
  const string BACON4 = " Stopper";
  const string PICKLES0 = " Tasteless";
  const string PICKLES1 = " Pickly";
  const string PICKLES2 = " Garden-Fresh";
  const string PICKLES3 = " Kermit";
  const string PICKLES4 = " Kale";
  const string CHEESE = "Cheezie ";
  const string SAUCE = "Saucie ";
  string Patty;
  string Bacon; 
  string Pickle;
  
  m_name = "";
  
  //Switch cases will assign the temp string name to be combined later
  switch (m_patty)
  {
    case 1:
      Patty = BURGERS1;
      break;
    case 2:
      Patty = BURGERS2;
      break;
    case 3:
      Patty = BURGERS3;
      break;
    case 4:
      Patty = BURGERS4;
      break;
  }
  switch (m_bacon)
  {
    case 0:
      Bacon = BACON0;
      break;
    case 1:
      Bacon = BACON1;
      break;
    case 2:
      Bacon = BACON2;
      break;
    case 3:
      Bacon = BACON3;
      break;
    case 4:
      Bacon = BACON4;
      break;
  }
  switch (m_pickle)
  {
    case 0:
      Pickle = PICKLES0;
      break;
    case 1:
      Pickle = PICKLES1;
      break;
    case 2:
      Pickle = PICKLES2;
      break;
    case 3:
      Pickle = PICKLES3;
      break;
    case 4:
      Pickle = PICKLES4;
      break;
  }
  if (getCheese() == 1)
  {
    m_name += CHEESE;
  } 
  if (getSauce() == 1)
  {
    m_name += SAUCE;
  }
  m_name += KRUSTY + Patty + Bacon + Pickle + BURGER;
  setPrice();
  return;
}

void Burger::setVirus(int v)
{
  if (v == 1)
  {
    m_virus = 1;
  }
  else 
  {
    m_virus = 0;
  }
  return;
}

void Burger::setPrice()
{
  m_price = (.75 * m_patty)+(.5 * m_bacon)+(.25*m_pickle)+(.5)
            +(.25*m_cheese)+(.1*m_sauce);
  return;
}

//ALLOWS FOR PRINTING OF BURGER CLASS
ostream & operator << (ostream & os,  Burger burg)
{
  os << burg.getName() << ": $" << burg.getPrice() << "(" << burg.getPatty() 
  << "patties, " << burg.getBacon() << "bacon, " << burg.getPickle() 
  << "pickles, " << (burg.getCheese()?"cheese, ":"") 
  << (burg.getSauce()?"sauce)":")") <<  endl;
  return os;
}
