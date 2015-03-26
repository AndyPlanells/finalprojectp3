#ifndef BALANCECHECK_H
#define BALANCECHECK_H

#include <string>
#include "check.h"

using std::string;

class balancecheck : public check
{
    double money;
public:
    balancecheck(string,int,double);
    virtual string toString()const;
    virtual double getTax();
    virtual double getDiscount(int);
    double getMoney()const;
};

#endif // BALANCECHECK_H
