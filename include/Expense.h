/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Date Last Modified: 11/23/2021
 *
 * This file contains the definitions of the functions belonging to the Expense class.
 *
 * */
#ifndef PERSONALFINANCE_EXPENSE_H
#define PERSONALFINANCE_EXPENSE_H

#include "Money.h"

/// The Expense class is used to perform various operations on an Expense object.
///
/// The Expense class contains several functions pertaining to interacting with an Expense.
/// It is used by the Account class when adding transactions to an account.
/// \author Dawson Dauphinais
class Expense : public Money
{
private:
    string name;
    Money price;
    string type;
    string date;
    bool isRecurring;

public:
    /// Sets the values of the Expense object.
    ///
    /// \param n The name of the expense.
    /// \param p The price of the expense.
    /// \param t The type of expense.
    /// \param d The date of the expense.
    /// \param iR Whether the expense is recurring or not.
    /// \author Dawson Dauphinais
    void setValues(string n, Money &p, string t, string d, bool iR);

    /// Sets the name of the Expense.
    ///
    /// \param name The name of the expense.
    /// \author Dawson Dauphinais
    void setName(string name);

    /// Sets the price of the Expense.
    ///
    /// \param price The price of the expense.
    /// \author Dawson Dauphinais
    void setPrice(Money price);

    /// Sets the type of the Expense.
    ///
    /// \param type The type of expense.
    /// \author Dawson Dauphinais
    void setType(string type);

    /// Sets the date of the Expense.
    ///
    /// \param date The date of the expense.
    /// \author Dawson Dauphinais
    void setDate(string date);

    /// Sets whether the Expense is recurring or not.
    ///
    /// \param isRecurring Whether the expense is recurring or not.
    /// \author Dawson Dauphinais
    void setIsRecurring(bool isRecurring);

    /// Returns the name of the Expense.
    ///
    /// \return The name of the expense.
    /// \author Dawson Dauphinais
    string getName();

    /// Returns the price of the Expense.
    ///
    /// \return The price of the expense.
    /// \author Dawson Dauphinais
    Money getPrice();

    /// Returns the type of the Expense.
    ///
    /// \return The type of the expense.
    /// \author Dawson Dauphinais
    string getType();

    /// Returns the date of the Expense.
    ///
    /// \return The date of the expense.
    /// \author Dawson Dauphinais
    string getDate();

    /// Returns whether the Expense is recurring or not.
    ///
    /// \return Whether the expense is recurring or not.
    /// \author Dawson Dauphinais
    bool getIsRecurring() const;

    /// Prints the values currently stored in the Expense object.
    ///
    /// Used mainly for debugging purposes.
    /// \author Dawson Dauphinais
    void printValues();

    /// Converts the Expense object into a string.
    ///
    /// \return A string format of the expense object.
    /// \author Dawson Dauphinais
    string toString();
};

#endif //PERSONALFINANCE_EXPENSE_H
