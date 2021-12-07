//
// Created by dawso on 11/13/2021.
//

#include "Income.h"

Income::Income(string d, Money m)
{
    date = d;
    amount = m;
}

Income::Income(Money m)
{
    amount = m;
}

void Income::setDate(string d)
{
    date = d;
}

void Income::setAmount(Money m)
{
    amount = m;
}

string Income::getDate()
{
    return date;
}

Money Income::getAmount()
{
    return amount;
}
