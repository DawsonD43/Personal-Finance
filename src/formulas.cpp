/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Date Last Modified: 10/25/2021
 *
 * This class contains several formulas that will be used by several other functions within the program.
 *
 * For example, the user may want to calculate how long it's going to take to pay off their credit card --
 * this class performs all the necessary math.
 *
 * */

#include <cstdlib>
#include <cstring>
#include <cmath>
#include "formulas.h"

using namespace std;

Formulas::Formulas() = default;

/*- Determines how much you earn in relation to how much you spend.*/
/*- Best for figuring out where to tighten your budget.*/
/*- If the number is negative, it means that too much money is being spent;
 *  positive values should be entered into savings*/
Money Formulas::cashFlow(Money &income, Money &expenses)
{
    Money ans;
    ans = income - expenses;
    return ans;
}

/*- Answers the question: "should you take $x payments each year for y years, or a lump sum of $z in y years."*/
/*- Best for seeing what it costs to pay someone with regular payments over time or upfront.*/
Money Formulas::futureValueOrdinaryAnnuity(Money &payment, double interestRate, int numPayments)
{
    double moneyval = Money::toDouble(payment);
    double numerator = Money::power((1.0 + interestRate), numPayments);
    numerator -= 1.0;
    numerator /= interestRate;
    numerator *= moneyval;
    return Money(numerator);
}

/*- The rate an investment would grow if the rate were constant.*/
/*- Best for determining average growth rate of any type of investment over multiple years.*/
double Formulas::compoundAnnualGrowthRate(Money &beginningVal, Money &endingVal, int numPeriods)
{
    double exp = 1.0 / numPeriods;
    double a = Money::toDouble(endingVal / beginningVal);
    a = pow(a, exp);
    a -= 1.0;
    return a * 100;
}

/*- The lower the average, the better.*/
/*- Best for measuring your liquidity and determining whether you can afford a loan.*/
double Formulas::leverageRatio(Money &totalLiabilities, Money &totalDebts, Money &totalIncome)
{
    Money numerator = totalLiabilities + totalDebts;
    Money denom = totalIncome;
    return toDouble(numerator / denom);
}

/*- A quick approximation of how long it will take to double an investment
 * based on the interest rate.*/
double Formulas::ruleOfSeventyTwo(double interestRate)
{
    return 72.0 / interestRate;
}

/*- Used to determine how long it will take to pay off a credit card (in months)*/
/*  based on the balance of the credit card, the monthly payment being made*/
/*  and the interest rate on the credit card.*/
double Formulas::creditCardEquation(Money balance, Money monthlyPayment, double interestRate)
{
    double R = interestRate / 100.0;
    R /= 12;

    double P = toDouble(monthlyPayment);
    double p1 = toDouble(balance) * R;
    p1 = P - p1;

    double numerator = P / p1;
    numerator = log(numerator);

    double den = 1 + R;
    den = log(den);
    double ans = numerator / den;
    return floor(ans * 100 + 0.5) / 100;
}

/*- calculates how much a monthly payment on will be on a debt.
 *- best for calculating the cost of long-term debt like mortgages, car loans, etc. */
Money Formulas::amortization(Money principal, double interestRate, int numPeriods, int paymentsPerPeriod)
{
    interestRate /= 100;
    double numerator = toDouble(principal) * (interestRate / paymentsPerPeriod);
    int exp = -1 * numPeriods * paymentsPerPeriod;
    double den = 1 + (interestRate / paymentsPerPeriod);
    den = pow(den, exp);
    den = 1 - den;
    double ans = numerator / den;
    return Money(ans);
}
