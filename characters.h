#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <string>

using std::string;

class characters
{
    string name, game;

public:
    characters(string,string);
    virtual string toString()=0;
    string getName();
    void setName(string);
    string getGame();
};

#endif // CHARACTERS_H
