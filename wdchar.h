#ifndef WDCHAR_H
#define WDCHAR_H

#include <string>
#include "characters.h"

using std::string;

class wdchar : public characters
{
    int level;
    string type, race, gender;
public:
    wdchar(string="",string="",int=0,string="",string="",string="");
    string toString();
    int getLevel()const;
    void setLevel(int);
    string getType()const;
    void setType(string);
    string getRace()const;
    void setRace(string);
    string getGender()const;
    void setGender(string);
};

#endif // WDCHAR_H
