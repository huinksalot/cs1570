//Programmer: Benjamin Huinker
//Section: F
//File: burger.h
//Purpose: Contains burger class definiton

#ifndef BURGER_H
#define BURGER_H

using namespace std;
#include <iostream>


class Burger
{
  public:
    //Desc: Default constructor
    //Pre: None
    //Post: Assigns random values for the toppings of the burger
    Burger(); 
    //Desc: Constructor that will make a burger based on values passed in
    //Pre: Parameters passed in are in the valid ranges
    //Post: New burger made with passed values
    Burger(const int p, const int b, const int pi,
                const int c, const int s, const int v);
    
    //Desc: Sets the member variable to value passed, or defaults to a random number within range
    //Pre: If passing value, value must be in proper range
    //Post: None
    void setName();
    void setPatty(const int p = (rand()%4) + 1) { m_patty = p; };
    void setBacon(int b = rand()%5) { m_bacon = b; };
    void setPickle(int p = rand()%5) { m_pickle= p; }; //SETTING FUNCTIONS
    void setCheese(int c = rand()%2) { m_cheese = c; };
    void setSauce(int s = rand()%2) { m_sauce = s; };
    void setVirus(int v = rand()%10);
    
    //Desc: Returns the respective value of the member variable
    //Pre: Valid variable set previously
    //Post: Returns the value of the burger
    int getPatty() const { return m_patty; };
    int getBacon() const { return m_bacon; };
    int getPickle() const { return m_pickle; };
    bool getCheese() const { return m_cheese; }; //GETTER FUNCTIONS
    bool getSauce() const { return m_sauce; };
    bool getVirus() const { return m_virus; };
    float getPrice() const { return m_price; };
    string getName() const { return m_name; };
    
    //Recognizing the operator overload for this class
    //Desc: Overloads so that you can print out type Burger variables
    //Pre: Values set for the variables of burg
    //Post: Prints out the name and price of the burger
    friend ostream & operator << (ostream & os, const Burger burg);

  private:
    int m_patty;
    int m_bacon;
    int m_pickle;
    bool m_cheese;
    bool m_sauce; //MEMBER VARIABLES
    bool m_virus;
    string m_name;
    float m_price;
    
    //Desc: Sets the price of the burger
    //Pre: Values set for the variables of the Burger
    //Post: None
    void setPrice(); //PRIVATE MEMBER FUNCTIONS

};

#endif
