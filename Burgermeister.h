//Programmer: Benjamin Huinker
//Section: F
//File: burgermeister.h
//Purpose: Contains burgermeister class definition

#ifndef BURGERMEISTER_H
#define BURGERMEISTER_H

using namespace std;
#include <iostream>

class Burgermeister
{
  public:
    Burgermeister();
    //Desc: Returns the amount of money Krusty has
    //Pre: Money must be set
    //Post: Returns krusty's money
    float getMoney() { return m_money; };
    //Desc: Operator overload for Krusty
    //Pre: Valid values passed to the function
    //Post: Allows for the operations to act as would be expected
    friend void operator+=(Burgermeister & krust, const int inc);
    friend void operator-=(Burgermeister & krust, const int dec);
    friend ostream& operator << (ostream& os, Burgermeister krust);
    
  private:
    string m_name;
    float m_money;
};
#endif