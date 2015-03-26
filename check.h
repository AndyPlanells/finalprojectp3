#ifndef CHECK_H
#define CHECK_H

#include <string>

using std::string;

class check
{
    double tax, discount;
    string boughtitem;
    int nocheck;
public:
    check(string="",int=0);
    virtual string toString()const=0;
    virtual double getTax()=0;
    virtual double getDiscount(int)=0;
    string getBoughtitem()const;
    void setBoughtitem(string);
    int getNocheck()const;
    void setNocheck(int);
};

#endif // CHECK_H
