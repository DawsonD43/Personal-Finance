/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Date Last Modified: 10/26/2021
 *
 * This class will allow for interacting with Expense objects.
 * This will make it easier to keep track of the user's expenses.
 *
 * */
#include "Expense.h"
#include <string>

using namespace std;

/*sets the initial values of the expense object*/
void Expense::setValues(string n, Money &p, string t, string d, bool iR)
{
    this->name = n;
    this->price = p;
    this->type = t;
    this->date = d;
    this->isRecurring = iR;
}

/*- sets the name of the current expense
 *- used for updating the name of an expense*/
void Expense::setName(string n)
{
    this->name = n;
}

/*- sets the price of the current expense
 *- used for updating the price*/
void Expense::setPrice(Money p)
{
    this->price = p;
}

/*- sets the type of the expense
 *- used for updating the current type of the expense*/
void Expense::setType(string t)
{
    this->type = t;
}

/*- sets the date that expense occurs/occurred
 *- used for updating the date of the expense*/
void Expense::setDate(string d)
{
    this->date = d;
}

/*- sets the value of isRecurring
 *- used for updating whether the expense is recurring or not*/
void Expense::setIsRecurring(bool iR)
{
    this->isRecurring = iR;
}

/*returns the name of the expense*/
string Expense::getName()
{
    return this->name;
}

/*returns the price of the expense*/
Money Expense::getPrice()
{
    return this->price;
}

/*returns the type of the expense*/
string Expense::getType()
{
    return this->type;
}

/*returns the date of the expense*/
string Expense::getDate()
{
    return this->date;
}

/*returns whether the expense is recurring or not*/
bool Expense::getIsRecurring() const
{
    return this->isRecurring;
}

/*prints the values of the Expense object*/
void Expense::printValues()
{
    cout << "NAME: " << Expense::getName()
         << "\nPRICE: " << Expense::getPrice()
         << "\nTYPE: " << Expense::getType()
         << "\nDATE: " << Expense::getDate()
         << "\nRECURRING? " << Expense::getIsRecurring()
         << endl;
}

/*converts the current Expense object into a string*/
string Expense::toString()
{
    string s;
    s = this->getName() + "/" + Money::toString(this->getPrice()) + "/" + this->getType() + "/" +
        to_string(this->getIsRecurring());
    return s;
}
