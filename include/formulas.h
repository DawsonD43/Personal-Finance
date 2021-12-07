/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Senior Project: Personal Finance System
 *
 * date last modified: 11/23/2021
 */
#ifndef PERSONALFINANCE_FORMULAS_H
#define PERSONALFINANCE_FORMULAS_H

#include <cstdlib>
#include <string>
#include <cmath>
#include "Money.h"

using namespace std;

/// The Formulas class is used to calculate different financial values.
///
/// This class performs different mathematical formulas pertaining to personal finance.
/// \author Dawson Dauphinais
class Formulas : public Money
{
public:
    /// Default constructor for the Formulas class.
    Formulas();

    /// Calculates total cash flow.
    ///
    /// \param income The income value as a Money object.
    /// \param expenses The total expenses value as a Money object.
    /// \return A Money object containing the cash flow based on the parameters.
    /// \author Dawson Dauphinais
    static Money cashFlow(Money &income, Money &expenses);

    /// Calculates the future value of an ordinary annuity.
    ///
    /// Best for seeing what it costs to pay someone with regular payments over time or upfront.
    /// \attention Enter the interest rate in the format: 0.456, this is equivalent to 4.56%.
    /// \param payment A Money object containing the cost of each payment.
    /// \param interestRate The interest rate.
    /// \param numPayments The number of payments to be made.
    /// \return A Money object containing the future value of the annuity.
    /// \author Dawson Dauphinais
    static Money futureValueOrdinaryAnnuity(Money &payment, double interestRate, int numPayments);

    /// Calculates the rate an investment would grow if the rate were constant.
    ///
    /// Best for determining average growth rate of any type of investment over multiple years.
    /// \param beginningVal A Money object containing the initial value.
    /// \param endingVal A Money object containing the final value.
    /// \param numPeriods The number of periods
    /// \return The compound annual growth rate.
    /// \author Dawson Dauphinais
    static double compoundAnnualGrowthRate(Money &beginningVal, Money &endingVal, int numPeriods);

    /// Calculates a leverage ratio.
    ///
    /// Best for measuring your liquidity and determining whether you can afford a loan.
    /// \note The lower the average is, the better.
    /// \param totalLiabilities A Money object containing the value of total liabilities.
    /// \param totalDebts A Money object containing the value of total debts.
    /// \param totalIncome A Money object containing the value of total income.
    /// \return The leverage ratio.
    /// \author Dawson Dauphinais
    static double leverageRatio(Money &totalLiabilities, Money &totalDebts, Money &totalIncome);

    /// Implements the Rule of 72.
    ///
    /// A quick approximation of how long it will take to double an investment based on an interest rate.
    /// \attention Enter the interest rate in the format: 4.56
    /// \param interestRate An interest rate.
    /// \return The amount of time, in years, that it would take to double an investment if the interest rate remained constant.
    /// \author Dawson Dauphinais
    static double ruleOfSeventyTwo(double interestRate);

    /// Determines how long it will take to pay off a credit card
    ///
    /// Based on the balance of the credit card, the monthly payment being made, and the interest rate on the credit card.
    /// \param balance A Money object containing the balance of the credit card.
    /// \param monthlyPayment A Money object containing the value of the monthly payment being made.
    /// \param interestRate The interest rate on the credit card.
    /// \attention Enter the interest rate in the format: 4.56
    /// \return How long it will take to pay off the credit card in years.
    /// \author Dawson Dauphinais
    static double creditCardEquation(Money balance, Money monthlyPayment, double interestRate);

    /// Calculates how much a monthly payment on will be on a debt.
    ///
    /// Best for calculating the cost of long-term debt like mortgages, car loans, etc.
    /// \attention Enter the interest rate in the format: 4.56
    /// \attention In most cases, the number of periods should be entered as the number of years the debt is, and the payments per period should be 12.
    /// \param principal A Money object containing the initial value of the debt.
    /// \param interestRate The interest rate.
    /// \param numPeriods The number of periods of the debt.
    /// \param paymentsPerPeriod The number of payments to be made per period.
    /// \return A Money object containing the value of the monthly payment on the given debt.
    /// \author Dawson Dauphinais
    static Money amortization(Money principal, double interestRate, int numPeriods, int paymentsPerPeriod);
};

#endif //PERSONALFINANCE_FORMULAS_H
