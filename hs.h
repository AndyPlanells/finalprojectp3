#ifndef HS_H
#define HS_H

#include "games.h"
#include "characters.h"
#include "hschar.h"
#include <string>

using std::string;
using std::vector;

class Hs : public games
{
    vector<hschar>mychars;
    bool founderpack;
public:
    Hs(bool=false,string="Hearthstone",bool=false);
    string toString();
    bool getFounderpack()const;
    void setFounderpack(bool);
    vector<hschar> getMychars()const;
    void setMychars(vector<hschar>);
};

#endif // HS_H
