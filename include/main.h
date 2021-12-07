/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Date Last Modified: 11/23/2021
 *
 * This file contains the definitions of the functions used by the main program.
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
 * */
#ifndef PERSONALFINANCE_MAIN_H
#define PERSONALFINANCE_MAIN_H

#include <iostream>
#include "Money.h"
#include "formulas.h"
#include "Expense.h"
#include "Account.h"
#include <nlohmann/json.hpp>

using namespace std;

int main(int argc, char **argv);

/// Lists the currently available accounts to choose from.
///
/// \param data The JSON data to parse.
/// \author Dawson Dauphinais
/// \see generateAccountMapFromJSON(map<string, Account>, json &)
void listAvailableAccounts(nlohmann::json &data);

/// Prints details of the current account.
///
/// \param acc The account to print values from.
/// \author Dawson Dauphinais
/// \see Account::printAccountDetails()
void viewAccount(Account &acc);

/// Updates the current account.
///
/// \param acc The account to update
/// \param accounts The map of the current accounts
/// \author Dawson Dauphinais
/// \see Account::getNameOfAccount() Account::setName() saveData() Account::setBalance() Account::getBalance() Account::addTransaction(Expense e)
void updateAccount(Account &acc, map<string, Account> &accounts);

/// Creates a new account.
///
/// Creates a new Account object and adds it to the map of current accounts.
/// \param accounts A map of the current accounts.
/// \author Dawson Dauphinais
/// \see Account::setValues(string, Money, map<string, string>, map<string, string>)
void createAccount(map<string, Account> &accounts);

/// Creates a new account if no accounts are found on start.
///
/// \param accounts A map of the current accounts.
/// \return An Account object to be used by the main program.
/// \note This is different than createAccount(map<string, Account>) in that it is used to create a new account if there are none present. It then returns an Account object to be used by the program.
/// \author Dawson Dauphinais
/// \see Account::setValues(string, Money, map<string, string>, map<string, string>) Account::addToIncomeList(Income i) saveData(map<string, Accounts>)
Account createAccountInit(map<string, Account> &accounts);

/// Allows the user to switch the account currently being used.
///
/// \param data The JSON data to generate the other account from.
/// \return An Account object containing data from the JSON file.
/// \author Dawson Dauphinais
/// \see fromJSON(json, Account, string)
Account switchAccounts(const nlohmann::json &data);

/// Provides various tools for the user to use.
///
/// \param acc The current Account.
/// \param accMap The map of current accounts.
/// \author Dawson Dauphinais
/// \see addIncome(Account, map<string, Account>) viewRecurring(Account) viewCashFlow(Account) nowOrLater() determineGrowthRate() determineLeverageRatio(Account) doubleAnInvestment() payOffCreditCard() calculateLongTermLoan()
void tools(Account &acc, map<string, Account> &accMap);

void addIncome(Account &acc, map<string, Account> &accMap);

void viewCashFlow(Account acc);

void viewRecurring(Account acc);

void nowOrLater();

void determineGrowthRate();

void determineLeverageRatio(Account acc);

void doubleAnInvestment();

void payOffCreditCard();

void calculateLongTermLoan();

void toJSON(nlohmann::json &j, map<string, Account> accs);

void fromJSON(const nlohmann::json &j, Account &acc, const string &nameOf);

Account fromJSON(nlohmann::json &j, const string &nameOf);

void generateAccountMapFromJSON(map<string, Account> &accMap, nlohmann::json data);

void printJSON(const nlohmann::json &j);

void loadAccountData(nlohmann::json &j, bool &fileFound);

void saveInit(nlohmann::json &j);

void saveData(map<string, Account> accounts);

#endif //PERSONALFINANCE_MAIN_H
