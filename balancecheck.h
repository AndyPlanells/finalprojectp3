#ifndef BALANCECHECK_H
#define BALANCECHECK_H

#include <string>
#include "check.h"

using std::string;

class balancecheck : public check
{
    int money;
public:
    balancecheck(string,int,int);
    virtual string toString()const;
    virtual double getTax();
    virtual double getDiscount(int);
    int getMoney()const;
};

#endif // BALANCECHECK_H
