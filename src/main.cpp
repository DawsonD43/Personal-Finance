/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Senior Project - Personal Finance Application
 *
 * Date Last Modified: 11/22/2021
 *
 * This file contains the logic for the main application,
 * to be used by the wxWidgets myApp class.
 *
 * */

#include <iostream>
#include <fstream>
#include <string>
#include "C:/Users/dawso/Documents/source/CS480/PersonalFinance_GUI/include/Money.h"
#include "C:/Users/dawso/Documents/source/CS480/PersonalFinance_GUI/include/formulas.h"
#include "C:/Users/dawso/Documents/source/CS480/PersonalFinance_GUI/include/Expense.h"
#include "C:/Users/dawso/Documents/source/CS480/PersonalFinance_GUI/include/Account.h"
#include <ios>
#include <iomanip>
#include "C:/Users/dawso/Documents/source/CS480/PersonalFinance_GUI/include/main.h"

using json = nlohmann::json;
using namespace std;

/*prints the details of the current account*/
void viewAccount(Account &acc)
{
    acc.printAccountDetails();
}

/*allows each aspect of an account object to be updated*/
void updateAccount(Account &acc, map<string, Account> &accMap)
{
    bool run = true;
    int in;
    string oldName;
    string s;
    string price;
    string category;
    string date;
    string yN;
    Expense e;
    while (run)
    {
        cout << "********************************" << endl;
        cout << "What would you like to update?" << endl;
        cout << "1. Name of Account." << endl;
        cout << "2. Balance" << endl;
        cout << "3. Transactions List" << endl;
        cout << "4. Exit" << endl;
        cout << "********************************" << endl;
        cin >> in;
        switch (in)
        {
        case 1:
            oldName = acc.getNameOfAccount();
            cout << "Enter the new name of the account." << endl;
            cin.ignore();
            getline(cin, s);
            acc.setName(s);
            cout << "Name of current account changed to: " << acc.getNameOfAccount() << endl;
            accMap[oldName] = acc;
            saveData(accMap);
            break;
        case 2:
            cout << "Enter the new balance." << endl;
            cin.ignore();
            getline(cin, price);
            acc.setBalance(Money(price));
            cout << "Current Balance is now: " << acc.getBalance() << endl;
            accMap[acc.getNameOfAccount()] = acc;
            saveData(accMap);
            break;
        case 3:
            cout << "ENTER THE FOLLOWING: " << endl;
            cout << "Name of Expense. " << endl;
            cin.ignore();
            getline(cin, s);
            e.setName(s);
            cout << "Price. (IGNORE $ SIGN)" << endl;
            getline(cin, price);
            e.setPrice(Money(price));
            cout << "Category. " << endl;
            getline(cin, category);
            e.setType(category);
            cout << "Date of Purchase (MMDDYYYY)" << endl;
            getline(cin, date);
            e.setDate(date);
            cout << "Is this a recurring expense? (y/n)" << endl;
            getline(cin, yN);
            if (yN == "y")
            {
                e.setIsRecurring(true);
            }
            else
            {
                e.setIsRecurring(false);
            }
            acc.addTransaction(e);
            accMap[acc.getNameOfAccount()] = acc;
            saveData(accMap);
            cout << "Updated Transactions List!" << endl;
            break;
        case 4:
            run = false;
            break;
        default:
            cout << "Invalid Option Entered! Please Try Again!" << endl;
        }
    }
}

/*returns an initial account object as well as fills the account map*/
Account createAccountInit(map<string, Account> &accounts)
{
    Account acc;
    string name;
    string balance;
    map<string, string> tran;
    map<string, string> v;
    cout << "Enter The Name of the Account." << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter Balance (Ignore the $ sign)." << endl;
    cin.ignore();
    getline(cin, balance);
    acc.setValues(name, Money(balance), tran, v);
    Income initial("Initial", Money(balance));
    acc.addToIncomeList(initial);
    cout << "Account: \"" << name << "\" created!" << endl;
    accounts[name] = acc;
    saveData(accounts);
    return acc;
}

/*creates a new account object*/
void createAccount(map<string, Account> &accounts)
{
    Account acc;
    string name;
    string balance;
    map<string, string> tran;
    map<string, string> v;
    cout << "Enter The Name of the Account." << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter Balance (Ignore the $ sign)." << endl;
    cin.ignore();
    getline(cin, balance);
    acc.setValues(name, Money(balance), tran, v);
    Income initial("Initial", Money(balance));
    acc.addToIncomeList(initial);
    cout << "Account: \"" << name << "\" created!" << endl;
    accounts[name] = acc;
    saveData(accounts);
}

/*switch between accounts*/
Account switchAccounts(const json &data)
{
    Account nAccount;
    string nAcc;
    cout << "Enter the name of the account you would like to use." << endl;
    cin.ignore();
    getline(cin, nAcc);
    fromJSON(data, nAccount, nAcc);
    return nAccount;
}

/*add income to the account*/
void addIncome(Account &acc, map<string, Account> &accMap)
{
    string income;
    string date;
    cout << "Enter Income." << endl;
    cin.ignore();
    getline(cin, income);
    cout << "Enter Date Received." << endl;
    cin.ignore();
    getline(cin, date);
    Money m(income);
    Income in(date, m);
    acc.addIncome(in);
    accMap[acc.getNameOfAccount()] = acc;
    cout << "Balance Updated!" << endl;
    cout << "Current Balance: " << acc.getBalance() << endl;
}

/*Display the current cash flow of the account*/
void viewCashFlow(Account acc)
{
    Money income = acc.getGrossIncome();
    Money expenses = acc.getTotalFromTransactions();
    Money cashFlow = Formulas::cashFlow(income, expenses);
    cout << "TOTAL CASHFLOW ON ACCOUNT: \"" << acc.getNameOfAccount() << "\" = " << cashFlow << endl;
}

/*- lists all recurring transactions
 *- TODO: use modulus to display next payment date*/
void viewRecurring(Account acc)
{
    cout << "RECURRING TRANSACTIONS: " << endl;
    map<string, string> transactions;
    map<string, string>::iterator it;
    transactions = acc.getRecurringList();
    for (it = transactions.begin(); it != transactions.end(); ++it)
    {
        cout << it->first << " => " << it->second << endl;
    }
}

/*- Answers the question: "should you take $x payments each year for y years, or a lump sum of $z in y years."*/
/*- Best for seeing what it costs to pay someone with regular payments over time or upfront.*/
void nowOrLater()
{
    string d;
    double interestRate;
    int numPayments;
    cout << "Enter the price of the payment: " << endl;
    cin >> d;
    cout << "Enter the interest rate: (i.e. 4.56)" << endl;
    cin >> interestRate;
    interestRate /= 100;
    cout << "Enter the number of payments to be made:" << endl;
    cin >> numPayments;
    Money payment(d);
    Money ans = Formulas::futureValueOrdinaryAnnuity(payment, interestRate, numPayments);
    cout << "Based on your input, the future value is: " << ans << endl;
}

/*determines the compound annual growth rate of an investment*/
void determineGrowthRate()
{
    string init, ending;
    int numPeriods;
    cout << "Enter the initial value of the investment: " << endl;
    cin >> init;
    cout << "Enter the final value of the investment: " << endl;
    cin >> ending;
    cout << "Enter the number of years on the investment as a whole number: " << endl;
    cin >> numPeriods;
    Money i(init);
    Money e(ending);
    double ans = Formulas::compoundAnnualGrowthRate(i, e, numPeriods);
    cout << "AVERAGE GROWTH RATE = " << ans << endl;
}

// TODO: implement a way to get total debts from the account;
/*determines the leverage ratio of the current account*/
void determineLeverageRatio(Account acc)
{
    string d;
    Money totalIncome = acc.getGrossIncome();
    Money liabilities = acc.getTotalFromTransactions();
    cout << "Enter total debts: " << endl;
    cin >> d;
    Money debts(d);
    double lR = Formulas::leverageRatio(liabilities, debts, totalIncome);
    cout << "Leverage Ratio = " << lR << endl;
    cout
        << "REMINDER: The lower, the better! \n Anything less than 1.0 is excellent. (This would indicate that you could pay off every debt within your income period!)"
        << endl;
}

/*Calculates how many years it will roughly take to double an investment based on the interest rate*/
void doubleAnInvestment()
{
    double in;
    cout << "Enter the interest rate on the investment. (i.e. 4.56)" << endl;
    cin >> in;
    double res = Formulas::ruleOfSeventyTwo(in);
    cout << "It will take roughly " << res << " years for this investment to double in value." << endl;
}

/*calculates how long it will take to pay off a credit card (in months)*/
void payOffCreditCard()
{
    string balance, monthlyPayment;
    double interestRate;
    cout << "Enter the current balance on the credit card." << endl;
    cin >> balance;
    cout << "Enter the monthly payment being made." << endl;
    cin >> monthlyPayment;
    cout << "Enter the interest rate on the credit card. (i.e. 4.56)" << endl;
    cin >> interestRate;
    double ans = Formulas::creditCardEquation(Money(balance), Money(monthlyPayment), interestRate);
    if (ans <= 12.0)
    {
        cout << "It will take " << ans << " months to pay off this credit card." << endl;
    }
    else
    {
        ans /= 12.0;
        cout << "It will take " << ans << " years to pay off this credit card." << endl;
    }
}

/*calculates how much a monthly payment will be on a debt*/
void calculateLongTermLoan()
{
    Money ans;
    string p;
    double interestRate;
    int term;
    cout << "Enter the loan amount." << endl;
    cin >> p;
    cout << "Enter the interest rate on the loan (i.e. 4.56)" << endl;
    cin >> interestRate;
    cout << "Enter the loan term. (in years)" << endl;
    cin >> term;
    ans = Formulas::amortization(Money(p), interestRate, term, 12);
    cout << "Monthly Payment: " << ans << endl;
}

/*various tools that provide different functionalities*/
void tools(Account &acc, map<string, Account> &accMap)
{
    bool run = true;
    int res;
    while (run)
    {
        cout << "*********************************************************************" << endl;
        cout << "1. Add Income" << endl;
        cout << "2. View Recurring Transactions" << endl;
        cout << "3. View CashFlow" << endl;
        cout << "4. Make/take a payment now or later?" << endl;
        cout << "5. Determine Average Growth Rate of an Investment" << endl;
        cout << "6. Check Leverage Ratio (On this account) " << endl;
        cout << "7. How long will it take to double an investment?" << endl;
        cout << "8. Determine how long it will take to pay off a credit card." << endl;
        cout << "9. Calculate the long-term cost of a loan." << endl;
        cout << "10. Exit" << endl;
        cout << "*********************************************************************" << endl;
        cin >> res;
        switch (res)
        {
        case 1:
            addIncome(acc, accMap);
            break;
        case 2:
            viewRecurring(acc);
            break;
        case 3:
            viewCashFlow(acc);
            break;
        case 4:
            nowOrLater();
            break;
        case 5:
            determineGrowthRate();
            break;
        case 6:
            determineLeverageRatio(acc);
            break;
        case 7:
            doubleAnInvestment();
            break;
        case 8:
            payOffCreditCard();
            break;
        case 9:
            calculateLongTermLoan();
            break;
        case 10:
            run = false;
            break;
        default:
            cout << "Invalid Response! Please Try Again." << endl;
        }
    }
}

/*- print the current JSON.
 *- used for debugging purposes.*/
void printJSON(const json &j)
{
    cout << setw(4) << j << endl;
}

/*convert Account object into JSON data*/
void toJSON(json &j, map<string, Account> accs)
{
    map<string, Account>::iterator it;
    for (it = accs.begin(); it != accs.end(); ++it)
    {
        json js = it->second.toJSON();
        j["accounts"][it->second.getNameOfAccount()] = js;
    }
}

/*convert JSON data to Account object*/
void fromJSON(const json &j, Account &acc, const string &nameOf)
{
    json accInfo = j["accounts"][nameOf];
    acc.setName(accInfo.at("name"));
    string bTemp = accInfo.at("balance");
    acc.setBalance(Money(bTemp));
    acc.setTransactions(accInfo.at("transactions"));
    acc.setRecurringList(accInfo.at("recurring_transactions"));
    acc.setIncomeList(accInfo.at("income"));
}

/*returns an Account object that is created from a json object*/
Account fromJSON(json &j, const string &nameOf)
{
    Account acc;
    acc.setName(j["name"]);
    string bTemp = j["balance"];
    acc.setBalance(Money(bTemp));
    acc.setTransactions(j["transactions"]);
    acc.setRecurringList(j["recurring_transactions"]);
    acc.setIncomeList(j["income"]);
    return acc;
}

/*fills the map of account objects with accounts that are generated from the json file*/
void generateAccountMapFromJSON(map<string, Account> &accMap, json data)
{
    for (json::iterator it = data["accounts"].begin(); it != data["accounts"].end(); ++it)
    {
        json j = it.value();
        const string &s = it.key();
        accMap[s] = fromJSON(j, s);
    }
}

/*loads the account data as a json object*/
void loadAccountData(json &j, bool &fileFound)
{
    std::ifstream in("C:/Users/dawso/Documents/source/CS480/PersonalFinance/data/accounts.json", std::ifstream::in);
    if (!in.fail())
    {
        fileFound = true;
        in >> j;
    }
}

/*creates the initial save data*/
void saveInit(json &j)
{
    std::ofstream os("C:/Users/dawso/Documents/source/CS480/PersonalFinance/data/accounts.json", ios::out);
    if (os.is_open())
    {
        os << std::setw(4) << j << std::endl;
        os.flush();
        os.close();
    }
    else
    {
        cerr << "Failed to open file: " << errno << endl;
        exit(-1);
    }
}

/*iterates through the account map and saves the account objects to the json file*/
void saveData(map<string, Account> accounts)
{
    json j;
    toJSON(j, std::move(accounts));
    std::ofstream os("C:/Users/dawso/Documents/source/CS480/PersonalFinance/data/accounts.json", ios::out);
    if (os.is_open())
    {
        os << std::setw(4) << j << std::endl;
        os.flush();
        os.close();
    }
    else
    {
        cerr << "Failed to open file: " << errno << endl;
        exit(-1);
    }
}

/*generates an account map from the json data and lists the names of the currently available accounts*/
void listAvailableAccounts(json &data)
{
    map<string, Account> mp;
    generateAccountMapFromJSON(mp, data);
    map<string, Account>::iterator it;
    cout << "************************" << endl;
    cout << "Found Accounts: " << endl;
    for (it = mp.begin(); it != mp.end(); ++it)
    {
        cout << it->first << endl;
    }
    cout << "************************" << endl;
}

int main(int argc, char **argv)
{
    json data;
    map<string, Account> accountMap; // <"Name", account>
    Account account;

    bool run = true;
    bool first = true;
    bool fileFound = false;

    while (run)
    {
        if (first)
        {
            first = false;
            loadAccountData(data, fileFound);
            if (fileFound)
            {
                listAvailableAccounts(data);
                string s;
                cout << "Enter the name of the account you would like to use." << endl;
                getline(cin, s);
                fromJSON(data, account, s);
                generateAccountMapFromJSON(accountMap, data);
            }
            else
            {
                ofstream out("C:/Users/dawso/Documents/source/CS480/PersonalFinance/data/accounts.json", ios::out);
                cout << "No Existing Data Found! " << endl;
                cout << "Please add an account before continuing!" << endl;
                cout << "Enter account data? y/n" << endl;
                string res;
                cin >> res;
                if (res == "y")
                {
                    json init;
                    init["accounts"] = nullptr;
                    saveInit(init);
                    account = createAccountInit(accountMap);
                }
                else if (res == "n")
                {
                    exit(0);
                }
                else
                {
                    cout << "Invalid Response... Exiting." << endl;
                    exit(1);
                }
            }
        }
        int option;
        cout << "******************************" << endl;
        cout << "SELECT AN OPTION: " << endl;
        cout << "1. View Account" << endl;
        cout << "2. Update Account" << endl;
        cout << "3. Create New Account" << endl;
        cout << "4. Switch Accounts" << endl;
        cout << "5. Tools" << endl;
        cout << "6. Exit Program" << endl;
        cout << "******************************" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            viewAccount(account);
            break;
        case 2:
            updateAccount(account, accountMap);
            break;
        case 3:
            createAccount(accountMap);
            break;
        case 4:
            saveData(accountMap);
            account = switchAccounts(data);
            cout << "Current Account: " << account.getNameOfAccount() << endl;
            break;
        case 5:
            tools(account, accountMap);
            saveData(accountMap);
            break;
        case 6:
            run = false;
            saveData(accountMap);
            cout << "Exiting! Goodbye." << endl;
            break;
        default:
            cout << "You have entered an invalid option. Please try again." << endl;
        }
    }
    return 0;
}
