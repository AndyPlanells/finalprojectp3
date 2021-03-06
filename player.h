#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "games.h"
#include "wow.h"
#include "d3.h"
#include "sc2.h"
#include "hs.h"
#include "characters.h"
#include "wdchar.h"
#include "shochar.h"
#include "hschar.h"
#include "check.h"
#include "balancecheck.h"
#include "gamecheck.h"

using std::string;

class player
{
    string name, lastname, username, password, email;
    int VisaCard, VisaCode,timesbalance, timesgames, mychecks;
    double balance;
    wow mywow;
    d3 myd3;
    sc2 mysc2;
    Hs myhs;
    vector<wdchar>mywowchars;
    vector<wdchar>myd3chars;
    vector<hschar>myhschars;
    vector<shochar>mysc2chars;
    vector<balancecheck> mybchecks;
    vector<gamecheck> mygchecks;
public:
    player(string="",string="",string="",string="",string="",int=0,int=0, double=0,wow=NULL,d3=NULL,sc2=NULL,Hs=NULL,int=0,int=0);
    string toString()const;
    string getName()const;
    void setName(string);
    string getLastname()const;
    void setLastname(string);
    string getUsername()const;
    void setUsername(string);
    string getPassword()const;
    void setPassword(string);
    string getEmail()const;
    void setEmail(string);
    int getVisaCard()const;
    void setVisaCard(int);
    int getVisaCode()const;
    void setVisaCode(int);
    double getBalance()const;
    void setBalance(double);
    wow getMyWoW()const;
    void setMyWoW(wow);
    d3 getMyd3()const;
    void setMyd3(d3);
    sc2 getMySc2()const;
    void setMySc2(sc2);
    Hs getMyHs()const;
    void setMyHs(Hs);
    vector<wdchar> getMywowchars()const;
    vector<wdchar> getMyd3chars()const;
    vector<shochar> getMySc2chars()const;
    vector<hschar> getMyhschars()const;
    void setwowchar(wdchar);
    void setd3char(wdchar);
    void setsc2char(shochar);
    void sethschar(hschar);
    vector<balancecheck> getMybcheck()const;
    vector<gamecheck> getMygcheck()const;
    void setbcheck(balancecheck);
    void setgcheck(gamecheck);
    int getTimesgames()const;
    int getTimesbalance()const;
    int getMychecks()const;
    void setMychecks(int);
    void setTimesgames(int);
    void setTimesbalance(int);


};

#endif // PLAYER_H
