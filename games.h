#ifndef GAMES_H
#define GAMES_H
#include <string>
#include "characters.h"
#include <vector>

using std::string;
using std::vector;

class games
{
    bool ifbought;
    string name;
public:
    games(bool, string);
    virtual string toString()const;
    bool getIfbought()const;
    void setIfbought(bool);
    string getName()const;
    void setName(string);

    string ActiveMessage(bool);
};

#endif // GAMES_H
