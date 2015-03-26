#ifndef SHOCHAR_H
#define SHOCHAR_H

#include "characters.h"
#include <string>

using std::string;

class shochar: public characters
{
    string story;
public:
    shochar(string="",string="",string="");
    string toString();
    string getStory()const;
    void setStory(string);
};

#endif // SHOCHAR_H
