#ifndef GAMECHECK_H
#define GAMECHECK_H
#include "check.h"
#include <string>

using std::string;

class gamecheck : public check
{
    double balance;
public:
    gamecheck(string, int, double);
    virtual string toString()const;
    virtual double getTax();
    virtual double getDiscount(int);
};

#endif // GAMECHECK_H
