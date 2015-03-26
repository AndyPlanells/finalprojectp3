#ifndef SC2_H
#define SC2_H

#include "games.h"
#include <string>
#include <vector>
#include "characters.h"
#include "shochar.h"

using std::vector;
using std::string;

class sc2 :public games
{
    vector<shochar> mychars;
    bool wol, hts;
public:
    sc2(bool=false,string="Starcraft II",bool=false,bool=false);
    string toString();
    bool getWol()const;
    void setWol(bool);
    bool getHts()const;
    void setHts(bool);
    vector<shochar> getMychars()const;
    void setMchars(vector<shochar>);
};

#endif // SC2_H
