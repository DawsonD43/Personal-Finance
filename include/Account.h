/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Date Last Modified: 11/23/2021
 *
 * This file contains the definitions of functions belonging to the Account class.
 * --------------------------------------------------------------------------------
 * */
/*
* This application contains software from:
* 
* Title: "JSON for Modern  C++"
* Author: Lohmann, Niels
*           -orchid: https://orcid.org/0000-0001-9037-795X
*           -email: mail@nlohmann.me
*            -website: https://nlohmann.me
*
* Version: 3.10.4
* License: MIT
* Repository-Code: "https://github.com/nlohmann"
* URL: https://json.nlohmann.me
*/

#ifndef PERSONALFINANCE_ACCOUNT_H
#define PERSONALFINANCE_ACCOUNT_H

#include "Money.h"
#include "Expense.h"
#include <vector>
#include "Income.h"
#include <map>
#include <nlohmann/json.hpp>

/// The Account class is used to perform various operations on an Account object.
///
/// The Account class contains several functions pertaining to interacting with the user's account.
/// It is used in the main program to create an account object and store various values in the object.
/// \author Dawson Dauphinais
class Account : public Money
{
private:
    string nameOfAccount;
    Money balance;
    Money grossIncome;
    map<string, string> transactions;
    map<string, string> recurring;
    map<string, string> incomeList;

public:
    /// Sets the values of Account.
    ///
    /// @param str The name of the account.
    /// @param bal The balance on the account.
    /// @param tr The map containing the list of transactions.
    /// @param inc The map containing the list of incomes.
    /// \author Dawson Dauphinais
    void setValues(string str, Money bal, map<string, string> tr, map<string, string> inc);

    /// Sets the name of the account.
    ///
    /// Used for updating the name of the account.
    /// \param name The name of the account.
    /// \author Dawson Dauphinais
    void setName(string name);

    /// Sets the account balance.
    ///
    /// Used for updating the balance on the account.
    /// \param bal The balance on the account.
    /// \author Dawson Dauphinais
    void setBalance(Money bal);

    /// Sets the transactions list on the account.
    ///
    /// Used for updating the list of transactions on the account.
    /// \param mp The map containing the list of transactions.
    /// \author Dawson Dauphinais
    void setTransactions(map<string, string> mp);

    /// Sets the recurring transactions list on the account.
    ///
    /// Used for updating the list of recurring transactions on the account.
    /// \param mp The map containing the list of recurring transactions.
    /// \author Dawson Dauphinais
    void setRecurringList(map<string, string> mp);

    /// Sets the income list on the account.
    ///
    /// Used for updating the list of incomes on the account.
    /// \param in The map containing the list of incomes on the account.
    /// \author Dawson Dauphinais
    void setIncomeList(map<string, string> in);

    /// Returns the name of the account.
    ///
    /// \return The name of the account.
    /// \author Dawson Dauphinais
    string getNameOfAccount();

    /// Returns the list of transactions on the account.
    ///
    /// \return The map of the current transactions on the account.
    /// \author Dawson Dauphinais
    map<string, string> getTransactions();

    /// Returns the list of incomes currently on the account.
    ///
    /// \return The map of the current incomes on the account.
    /// \author Dawson Dauphinais
    map<string, string> getIncomeList();

    /// Returns the list of recurring transactions on the account.
    ///
    /// \return The map of the current recurring transactions on the account.
    /// \author Dawson Dauphinais
    map<string, string> getRecurringList();

    /// Returns the current balance of the account.
    ///
    /// \return The current balance of the account.
    /// \author Dawson Dauphinais
    Money getBalance();

    /// Returns the total amount spent on transactions.
    ///
    /// \return The total value of all the transactions.
    /// \author Dawson Dauphinais
    Money getTotalFromTransactions();

    /// Returns the gross income on the account.
    ///
    /// \return The gross income on the account.
    /// \author Dawson Dauphinais
    Money getGrossIncome();

    /// Returns the total amount of income on the account.
    ///
    /// \return The total amount of income on the account.
    /// \author Dawson Dauphinais
    Money getTotalIncome();

    /// Adds an income to the income list.
    ///
    /// \param i An income object.
    /// \author Dawson Dauphinais
    void addToIncomeList(Income i);

    /// Adds an expense to the transaction list.
    ///
    /// \param e An Expense object.
    /// \author Dawson Dauphinais
    void addTransaction(Expense &e);

    /// Prints a list of all transactions on the account.
    ///
    /// Used to view all transactions that have occurred on the account.
    /// \author Dawson Dauphinais
    void printTransactions();

    /// Prints a list of all incomes on the account.
    ///
    /// Used to view all incomes that have occurred on the account.
    /// \author Dawson Dauphinais
    void printIncomeList();

    /// Prints all details of the current account.
    ///
    /// Prints the name of the account, the current balance, the transaction history, and the income history.
    /// \author Dawson Dauphinais
    void printAccountDetails();

    /// Updates the current balance of the account.
    ///
    /// \param m A Money object that will change the balance of the account.
    /// \author Dawson Dauphinais
    void updateBalance(Money &m);

    /// Adds an income to the current account.
    ///
    /// This function will update the income list, the gross income on the account, as well as the current balance of the account.
    /// \param i An Income object.
    /// \see addToIncomeList(Income i) addToGrossIncome(Money m) updateBalance(Money &m)
    /// \author Dawson Dauphinais
    void addIncome(Income i);

    /// Adds a value to the gross income.
    ///
    /// Used to add to the gross income on the current account.
    /// \param m A Money object that will be added to the gross income on the account.
    /// \author Dawson Dauphinais
    void addToGrossIncome(Money m);

    /// Converts the Account object into a nlohmann::json object.
    ///
    /// Used for storing the account information in json format.
    /// \return A nlohmann::json object that is the equivalent of the current Account object.
    /// \author Dawson Dauphinais
    nlohmann::json toJSON();
};

#endif //PERSONALFINANCE_ACCOUNT_H
