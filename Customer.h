//Programmer: Benjamin Huinker
//Section: F
//File: customer.h
//Purpose: Contains customer class definition

#ifndef CUSTOMER_H
#define CUSTOMER_H

using namespace std;
#include "Burger.h"
#include "Burgermeister.h"

class Customer
{
  public:
    //Desc: Default constructor will randomly assign the member variables
    //Pre: None
    //Post: Randomly sets values for the properties of customer
    Customer(); //CONSTRUCTOR
    
    //Desc: Sets the values of the variables, random if no value is passed
    //Pre: If passing values, they should be within valid range
    //Post: Values set to the variables
    void setName();
    void setMoney(int m =((rand() % 5100) + 2500)/100) { m_money = m; }; 
    void setWeight(int w =(rand() % 161) + 90) {m_weight = w; };  
    void setLiving() { m_isLiving = 1; };
    void setCholesterol(int c =(rand() % 271) + 30) { m_cholesterol = c; }; 
    void setHealth(int h = (rand()%100)+1) { m_health = h; };
    void setContestant(int c = 1) { m_contestant = c; };
    void setEaten(int e = 0) { m_totEaten = e; };
    void setStatus(int s = 1) { m_status = s; };
    
    //Desc: Returns the values of the respective variable
    //Pre: Valid values set beforehand
    //Post: Returns respective value
    string getName(){ return m_name; };
    float getMoney(){ return m_money; };
    int getWeight(){ return m_weight; };
    bool getLiving(){ return m_isLiving; };  //GETTER FUNCTIONS
    short getCholesterol(){ return m_cholesterol; };
    int getHealth(){ return m_health; };
    bool getContestant(){ return m_contestant; };
    int getEaten() { return m_totEaten; };
    bool getStatus() {return m_status; };
    
    //Desc: Will do a prelim check if the customer can eat
    //Pre: Valid array and index variable passed
    //Post: Will print their condition or make them eat
    void tryEat(Burgermeister  & krusty, int spot, Customer conts[]);
    //Desc: The customer will eat a burger, possibly puke
    //Pre: Valid burger, array and index value passed
    //Post: Results in calling the puke functions if chance is high enough
    void eat(const Burger burg, Burgermeister  & krusty, int spot,
             Customer conts[]);
    //Desc: Uses recursion to walk down the array with chances of puking 
    //Pre: Valid array and index variable
    //Post: Can continue or stop the puking line
    void pukeDown(Burgermeister & krusty, int spot, Customer conts[]);
    //Desc: Uses recursion to walk up the array with chances of puking 
    //Pre: Valid array and index variable
    //Post: Can continue or stop the puking line
    void pukeUp(Burgermeister & krusty, int spot, Customer conts[]);
    //Desc: Handles the foodfight mechanic of the contest, uses recursion
    //Pre: Valid array 
    //Post: Will continue or end the foodfight based on the chances
    void toss(Burgermeister & krusty, Customer conts[]);
    
    //Recognizing the operator overload for this class
    //Desc: Allows for printing of the class Customer
    //Pre: Values set for the customer variables
    //Post: Prints out the info on the customer
    friend ostream & operator << (ostream & os, Customer cust);
    
  private:
    char m_name[30];
    float m_money;
    int m_weight; //MEMBER VARIABLES
    short m_cholesterol; 
    bool m_isLiving;
    int m_health;
    bool m_contestant;
    int m_totEaten;
    bool m_status;
};


#endif
