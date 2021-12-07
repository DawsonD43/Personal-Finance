/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Date Last Modified: 11/23/2021
 *
 * */

#ifndef PERSONALFINANCE_MONEY_H
#define PERSONALFINANCE_MONEY_H

#include <iostream>
#include <cmath>
#include <string>
// #include <algorithm>

using namespace std;

/// The Money class is used to allow operations on Money.
///
/// This class overloads the basic arithmetic operators, allowing for operations to be performed
/// on a monetary value.
/// This class also serves as a basis for several other classes, allowing them to inherit from this class
/// so that Money objects may be returned by functions belonging to other classes.
/// \author Dawson Dauphinais
class Money
{
public:
    /// Default constructor for the Money class.
    Money();

    /// Constructor for the Money class based on a double.
    ///
    /// Constructs a money object from a double value.
    /// \param m A monetary value given as a double.
    /// \author Dawson Dauphinais
    explicit Money(double m);

    /// Constructor for the Money class based on two integers.
    ///
    /// \param d The dollar amount as an integer.
    /// \param c The cent amount as an integer.
    /// \author Dawson Dauphinais
    Money(int d, int c);

    /// Constructor for the Money class based on a string.
    ///
    /// Parses a string and splits the value at the decimal into dollars and cents.
    /// If there is no decimal, the dollar amount is whatever the string is, and cents will be 0.
    /// \param s The string containing the monetary value.
    /// \author Dawson Dauphinais
    explicit Money(const string &s);

    /// Overloads the - operator for the Money class.
    ///
    /// This allows for negative values in the Money class.
    /// \return A Money object containing the negative value.
    /// \author Dawson Dauphinais
    Money operator-() const;

    /// Overloads the + operator for the Money class.
    ///
    /// This allows for addition of Money objects.
    /// \param m A Money object to be added to the current Money object.
    /// \return A Money object containing the result of the addition.
    /// \author Dawson Dauphinais
    Money operator+(const Money &m) const;

    /// Overloads the - operator for the Money class.
    ///
    /// This allows for subtraction of Money objects.
    /// \param m A Money object to be subtracted from the current Money object.
    /// \return A Money object containing the result of the subtraction.
    /// \author Dawson Dauphinais
    Money operator-(const Money &m) const;

    /// Overloads the * operator for the Money class.
    ///
    /// This allows for multiplication of Money objects.
    /// \attention This may cause precision errors. It is unlikely, but not impossible.
    /// \param val The value to multiply the Money object by.
    /// \return A Money object containing the result of the multiplication.
    /// \author Dawson Dauphinais
    Money operator*(double val) const;

    /// Overloads the / operator for the Money class.
    ///
    /// This allows for the division of Money objects.
    /// \attention This could potentially cause precision errors. Unlikely, but not impossible.
    /// \param m The value to divide the current Money object by.
    /// \return A Money object containing the result of the division.
    /// \author Dawson Dauphinais
    Money operator/(double m) const;

    /// Overloads the / operator for the Money class.
    ///
    /// This allows for the division of Money objects
    /// \attention This could potentially cause precision errors. Unlikely, but not impossible.
    /// \param m The Money object to divide the current Money object by.
    /// \return A Money object containing the result of the division.
    /// \author Dawson Dauphinais
    Money operator/(Money &m) const;

    /// Implements the power function for the Money class.
    ///
    /// Allows a Money object to be raised to a specified power.
    /// \param m A Money object containing the initial value.
    /// \param exp The exponent.
    /// \return A Money object containing the result.
    /// \author Dawson Dauphinais
    static Money power(Money &m, int exp);

    /// Helper function for the power function of the Money class.
    ///
    /// \see power(Money &m, int exp)
    /// \param d The monetary value.
    /// \param exp The exponent.
    /// \return The result of raising the monetary value to the specified power.
    /// \author Dawson Dauphinais
    static double power(double d, int exp);

    /// Overloads the == operator for the Money class.
    ///
    /// Allows equality checking between to Money objects..
    /// \param m A Money object to compare with current object.
    /// \return True if the objects are equal; false otherwise.
    /// \author Dawson Dauphinais
    bool operator==(const Money &m) const;

    /// Overloads the << operator for the Money class.
    ///
    /// This allows Money objects to be printed as follows: $4.56
    /// \param out The ostream for the operator.
    /// \param m The Money object to be printed to the screen.
    /// \return An ostream containing the formatted output.
    /// \author Dawson Dauphinais
    friend ostream &operator<<(ostream &out, const Money &m);

    /// Converts a Money object to a double value.
    ///
    /// \attention Could potentially cause loss of precision. Unlikely, but not impossible.
    /// \param m The Money object to be converted.
    /// \return The value as a double.
    /// \author Dawson Dauphinais
    static double toDouble(const Money &m);

    /// Converts a Money object to a string.
    ///
    /// \param m1 The Money object to be converted.
    /// \return The value as a string.
    /// \author Dawson Dauphinais
    static string toString(const Money &m1);

private:
    int dollars{};
    int cents{};
};

#endif //PERSONALFINANCE_MONEY_H
