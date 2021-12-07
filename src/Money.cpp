/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Date Last Modified: 11/23/2021
 *
 * This file includes the definitions of the Money class. This will be used by other files so that the program can work with amounts of money rather than just double values.
 *
 * */

#include <iostream>
#include <cmath>
#include <string>
#include "Money.h"

using namespace std;

Money::Money() = default;

Money::Money(int d, int c)
{
    this->dollars = d;
    this->cents = c;
}

Money::Money(double m)
{
    int d = (int)m;
    int cs;
    if (d == 0)
    {
        double cd = floor(m * 100);
        cs = (int)cd;
    }
    else
    {
        double v = m - d;
        cs = ceil(v * 100);
    }
    this->dollars = d;
    this->cents = cs;
}

/*Money constructor for string arguments*/
Money::Money(const string &s)
{
    size_t found = s.find('.');
    if (found == string::npos)
    {
        dollars = stoi(s);
        cents = 0;
    }
    else
    {
        dollars = stoi(s.substr(0, s.find('.')));
        cents = stoi(s.substr(s.find('.') + 1, s.length() - 1));
    }
}

Money Money::operator-() const
{
    int negative = -(dollars * 100 + cents);
    Money m(negative);
    return m;
}

Money Money::operator+(const Money &m) const
{
    Money ans;
    int dTotal = this->dollars + m.dollars;
    int cTotal = this->cents + m.cents;
    if (cTotal >= 100)
    {
        dTotal += 1;
        cTotal -= 100;
    }
    ans.dollars = dTotal;
    ans.cents = cTotal;
    return ans;
}

Money Money::operator-(const Money &m) const
{
    Money ans;
    int dTotal = this->dollars - m.dollars;
    int cTotal;
    if (this->cents < m.cents)
    {
        dTotal -= 1;
        int c = this->cents + 100;
        cTotal = c - m.cents;
        ans.cents = cTotal;
    }
    else
    {
        cTotal = this->cents - m.cents;
        ans.cents = cTotal;
    }
    ans.dollars = dTotal;
    return ans;
}

bool Money::operator==(const Money &m) const
{
    int t = (dollars * 100 + cents);
    int mTotal = (m.dollars * 100 + m.cents);
    return t == mTotal;
}

ostream &operator<<(ostream &out, const Money &m)
{
    if (m.cents < 10)
    {
        out << "$" << m.dollars << ".0" << m.cents;
    }
    else
    {
        out << "$" << m.dollars << "." << m.cents;
    }
    return out;
}

Money Money::operator*(double val) const
{
    double mon = toDouble(Money(this->dollars, this->cents));
    double res = mon * val;
    return Money(res);
}

double Money::toDouble(const Money &m)
{
    double ans;
    int d = m.dollars;
    int c = m.cents;
    double cd = (double)c / 100;
    ans = (double)d;
    ans += cd;
    return floor(ans * 100 + 0.5) / 100;
}

Money Money::operator/(double m) const
{
    double d = toDouble(Money(this->dollars, this->cents));
    double res = d / m;
    return Money(res);
}

Money Money::power(Money &m, int exp)
{
    double d = toDouble(m);
    d = power(d, exp);
    return Money(d);
}

double Money::power(double d, int exp)
{
    double ans = floor(d * 100 + 0.5) / 100;
    if (exp == 0)
    {
        return 1;
    }
    return (ans * power(ans, exp - 1));
}

Money Money::operator/(Money &m) const
{
    double v1 = toDouble(Money(this->dollars, this->cents));
    double v2 = toDouble(m);
    double ans = v1 / v2;
    return Money(floor(ans * 100 + 0.5) / 100);
}

string Money::toString(const Money &m1)
{
    if (m1.cents == 0)
    {
        return to_string(m1.dollars) + ".00";
    }
    return to_string(m1.dollars) + "." + to_string(m1.cents);
}
