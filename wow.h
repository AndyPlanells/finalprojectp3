#ifndef WOW_H
#define WOW_H

#include "games.h"
#include <string>
#include <vector>
#include "characters.h"
#include "wdchar.h"

using std::vector;
using std::string;

class wow:public games
{

    vector<wdchar> mychars;
    int gametime;
    bool wowstat, tbc, wotlk, cata, mop, wod;
public:
    wow(bool=false,string="World of Warcraft",int=0,bool=false,bool=false,bool=false,bool=false,bool=false,bool=false);
    string toString();
    int getGametime()const;
    void setGametime(int);
    bool getWowstat()const;
    void setWowstat(bool);
    bool getTbc()const;
    void setTbc(bool);
    bool getWotlk()const;
    void setWotlk(bool);
    bool getCata()const;
    void setCata(bool);
    bool getMop()const;
    void setMop(bool);
    bool getWod()const;
    void setWod(bool);
};

#endif // WOW_H
