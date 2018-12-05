//Programmer: Benjamin Huinker
//Section: F
//File: burgermeisterfunctions.cpp
//Purpose: Overrides class functions within burgermeister.h

using namespace std;
#include "Burgermeister.h"

//Default contructor
Burgermeister::Burgermeister()
{
  m_name = "Krusty";
  m_money = 100;
}

void operator+=(Burgermeister & krust, const int inc)
{
  krust.m_money += inc;
  return;
}

void operator -=(Burgermeister & krust, const int dec)
{
  krust.m_money -= dec;
  return;
}

ostream& operator << (ostream& os, Burgermeister krust)
{
  os << krust.m_name << " has $" << krust.m_money << endl;
  return os;
}

