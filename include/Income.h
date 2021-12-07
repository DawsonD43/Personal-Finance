/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Date Last Modified: 11/23/2021
 *
 * This file contains the definitions of the functions belonging to the Income class.
 * */

#ifndef PERSONALFINANCE_INCOME_H
#define PERSONALFINANCE_INCOME_H

#include "Money.h"

/// This class is used to store income objects.
///
/// It is used by other classes to store income objects as a date and amount.
/// \author Dawson Dauphinais
class Income : public Money
{
private:
    string date;
    Money amount;

public:
    /// Constructor based on a date and monetary amount.
    ///
    /// \param d The date of the income.
    /// \param m The Money amount of the income.
    /// \author Dawson Dauphinais
    Income(string d, Money m);

    /// Constructor based on a monetary amount.
    ///
    /// \author Dawson Dauphinais
    /// \param m The Money amount of the income.
    explicit Income(Money m);

    /// Returns the date of the income.
    ///
    /// \return The date of the income.
    /// \author Dawson Dauphinais
    string getDate();

    /// Returns the amount of the income.
    ///
    /// \return A Money object containing the amount of the income.
    /// \author Dawson Dauphinais
    Money getAmount();

    /// Sets the date of the income.
    ///
    /// \param d The date.
    /// \author Dawson Dauphinais
    void setDate(string d);

    /// Sets the amount of the income.
    ///
    /// \param m A Money object containing the amount.
    /// \author Dawson Dauphinais
    void setAmount(Money m);

    /// Converts the income object into a string
    ///
    /// Used mainly for debugging purposes.
    /// \author Dawson Dauphinais
    void toString();
};

#endif //PERSONALFINANCE_INCOME_H
