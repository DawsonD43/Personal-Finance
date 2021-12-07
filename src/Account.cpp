/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Date Last Modified: 11/13/2021
 *
 * This class contains several functions that will allow the user to create an account
 * and then interact with their account.
 *
 * */

#include "Account.h"

/*sets the initial values of the name of the account and the balance.*/
void Account::setValues(string str, Money bal, map<string, string> tr, map<string, string> inc)
{
    this->nameOfAccount = str;
    this->balance = bal;
    this->transactions = tr;
    this->incomeList = inc;
}

/*- sets the current name of the account
 *- used for updating the name of account*/
void Account::setName(string name)
{
    this->nameOfAccount = name;
}

/*- sets the current balance of the account
 *- used for updating the balance*/
void Account::setBalance(Money bal)
{
    this->balance = bal;
}

void Account::setTransactions(map<string, string> mp)
{
    this->transactions = mp;
}

void Account::setRecurringList(map<string, string> mp)
{
    recurring = mp;
}

void Account::setIncomeList(map<string, string> in)
{
    this->incomeList = in;
}

/*returns the name of the account*/
string Account::getNameOfAccount()
{
    return this->nameOfAccount;
}

/*return the account's balance*/
Money Account::getBalance()
{
    return this->balance;
}

map<string, string> Account::getIncomeList()
{
    return this->incomeList;
}

map<string, string> Account::getRecurringList()
{
    return recurring;
}

/*returns the total price of transactions on the account */
Money Account::getTotalFromTransactions()
{
    map<string, string>::iterator it;
    Money total(0, 0);
    for (it = this->transactions.begin(); it != this->transactions.end(); ++it)
    {
        Money price(it->second);
        total = total + price;
    }
    return total;
}

Money Account::getGrossIncome()
{
    Money total(0, 0);
    map<string, string>::iterator it;
    for (it = this->incomeList.begin(); it != this->incomeList.end(); ++it)
    {
        total = total + Money(it->second);
    }
    return total;
}

Money Account::getTotalIncome()
{
    Money income = getGrossIncome();
    Money expenses = getTotalFromTransactions();
    return income - expenses;
}

map<string, string> Account::getTransactions()
{
    return this->transactions;
}

/*- adds an expense to the list of transactions associated with the account
 *- stores the transaction as "NAME/DATE"*/
void Account::addTransaction(Expense &e)
{
    string key = e.getName() + "/" + e.getDate();
    Money price = e.getPrice();
    if (e.getIsRecurring())
    {
        recurring[key] = Money::toString(price);
        transactions[key] = Money::toString(price);
    }
    else
    {
        this->transactions[key] = Money::toString(price);
    }
    updateBalance(price);
}

/*updates the current balance of the account*/
void Account::updateBalance(Money &m)
{
    Money init = this->getBalance();
    Money res = init - m;
    this->setBalance(res);
}

/*lists all transactions on the current account*/
void Account::printTransactions()
{
    map<string, string>::iterator it;
    for (it = this->transactions.begin(); it != this->transactions.end(); ++it)
    {
        cout << it->first << " => " << Money(it->second) << endl;
    }
}

void Account::printIncomeList()
{
    map<string, string>::iterator it;
    for (it = this->incomeList.begin(); it != this->incomeList.end(); ++it)
    {
        cout << it->first << " => " << Money(it->second) << endl;
    }
}

/*prints all details within the current account*/
void Account::printAccountDetails()
{
    cout << "ACCOUNT: " << this->getNameOfAccount() << endl;
    cout << "CURRENT BALANCE: " << this->getBalance() << endl;
    cout << "TRANSACTION HISTORY: " << endl;
    Account::printTransactions();
    cout << "INCOME HISTORY: " << endl;
    Account::printIncomeList();
}

/*converts the Account object into a string*/
nlohmann::json Account::toJSON()
{
    nlohmann::json j;
    j["name"] = nameOfAccount;
    j["balance"] = Money::toString(balance);
    j["transactions"] = transactions;
    j["recurring_transactions"] = recurring;
    j["income"] = incomeList;
    return j;
}

void Account::addToIncomeList(Income i)
{
    string key = i.getDate();
    Money price = i.getAmount();
    this->incomeList[key] = Money::toString(price);
}

void Account::addToGrossIncome(Money m)
{
    this->grossIncome = grossIncome + m;
}

/*adds any income to the balance on the current account*/
void Account::addIncome(Income i)
{
    double init = Money::toDouble(i.getAmount());
    init *= -1.0;
    Money ret(init);
    addToIncomeList(i);
    addToGrossIncome(ret);
    updateBalance(ret);
}
