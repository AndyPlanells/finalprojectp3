#ifndef HSCHAR_H
#define HSCHAR_H

#include "characters.h"
#include <string>

using std::string;

class hschar : public characters
{
    string type, info;
    int manacost;
public:
    hschar(string="",string="",string="",string="",int=0);
    string toString();
    string getType()const;
    void setType(string);
    string getInfo()const;
    void setinfo(string);
    int getManacost()const;
    void setManacost(int);
};

#endif // HSCHAR_H
